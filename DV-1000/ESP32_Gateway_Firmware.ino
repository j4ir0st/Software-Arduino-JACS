/* ========================================================================== */
/* GATEWAY IOT ESP32 PARA DOSIFICADOR INDUSTRIAL DV-1000                     */
/* Puente de comunicación entre Arduino Mega 2560 y Cloud (Django / Supabase) */
/* ========================================================================== */
/*
 * INSTRUCCIONES DE USO:
 * 1. Abrir este archivo en Arduino IDE.
 * 2. Seleccionar la placa: "ESP32 Dev Module" o "NodeMCU-32S".
 * 3. Configurar tus credenciales de WiFi y las URLs de tu API de Vercel / Supabase abajo.
 * 4. Conectar el ESP32 por USB y presionar Subir.
 * 
 * CONEXIÓN CON EL ARDUINO MEGA 2560:
 * - ESP32 Pin 16 (RX2) <--- Arduino Mega Pin 18 (TX1) [con divisor resistivo 1k/2k]
 * - ESP32 Pin 17 (TX2) ---> Arduino Mega Pin 19 (RX1) [conexión directa]
 * - ESP32 GND          <--- Arduino Mega GND
 * - ESP32 VIN (5V)     <--- Fuente 5V del tablero
 * ==========================================================================
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

// 1. Configuración de Red WiFi
const char* WIFI_SSID     = "TU_RED_WIFI";
const char* WIFI_PASSWORD = "TU_PASSWORD_WIFI";

// 2. Configuración de API Django en Vercel (o Supabase)
// Reemplaza con tu dominio real de Vercel
const char* URL_API_TELEMETRIA = "https://tu-proyecto.vercel.app/api/v1/telemetria/";
const char* URL_API_DESCARGAS  = "https://tu-proyecto.vercel.app/api/v1/descargas/";
const char* API_KEY_SECRET     = "Bearer TU_TOKEN_SECRETO_O_API_KEY";

// Puerto serie 2 del ESP32 dedicado a comunicarse con el Arduino Mega
HardwareSerial SerialMega(2);

unsigned long ultimo_intento_wifi = 0;
String buffer_mega = "";

void conectar_wifi() {
  if (WiFi.status() == WL_CONNECTED) return;
  
  Serial.print("Conectando a WiFi: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int reintentos = 0;
  while (WiFi.status() != WL_CONNECTED && reintentos < 20) {
    delay(500);
    Serial.print(".");
    reintentos++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Conectado con exito!");
    Serial.print("IP Asignada: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nNo se pudo conectar al WiFi. Reintentando luego...");
  }
}

void setup() {
  Serial.begin(115200);           // Monitor serie para depuración USB
  SerialMega.begin(115200, SERIAL_8N1, 16, 17); // RX=16, TX=17 hacia Arduino Mega

  Serial.println("\n=== GATEWAY IOT DV-1000 INICIANDO ===");
  conectar_wifi();
}

void loop() {
  // 1. Mantener viva la conexión WiFi
  if (WiFi.status() != WL_CONNECTED && millis() - ultimo_intento_wifi > 10000) {
    ultimo_intento_wifi = millis();
    conectar_wifi();
  }

  // 2. Escuchar tramas JSON que envía el Arduino Mega por SerialMega
  while (SerialMega.available()) {
    char c = (char)SerialMega.read();
    if (c == '\n') {
      buffer_mega.trim();
      if (buffer_mega.length() > 0) {
        Serial.print("Recibido de Mega: ");
        Serial.println(buffer_mega);

        // Enviar a la nube si hay conexión
        if (WiFi.status() == WL_CONNECTED) {
          enviar_a_cloud(buffer_mega);
        }
        buffer_mega = "";
      }
    } else {
      if (buffer_mega.length() < 512) {
        buffer_mega += c;
      }
    }
  }
}

/* 
 * enviar_a_cloud:
 * Realiza la petición HTTPS POST hacia Django en Vercel con la carga JSON recibida.
 * Si el servidor responde con un comando pendiente, lo reenvía al Arduino Mega.
 */
void enviar_a_cloud(String json_payload) {
  WiFiClientSecure client;
  client.setInsecure(); // Permite conectar a HTTPS sin validar certificado raíz estático

  HTTPClient http;
  
  // Discriminar entre evento de descarga puntual o telemetría periódica
  String endpoint_url = URL_API_TELEMETRIA;
  if (json_payload.indexOf("\"event\":\"DESCARGA\"") >= 0) {
    endpoint_url = URL_API_DESCARGAS;
  }

  if (http.begin(client, endpoint_url)) {
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", API_KEY_SECRET);

    int codigo_http = http.POST(json_payload);
    
    if (codigo_http > 0) {
      String respuesta = http.getString();
      Serial.printf("Respuesta Cloud [%d]: %s\n", codigo_http, respuesta.c_str());

      // Si la API en Django devuelve un comando para la máquina, enviarlo por Serial al Mega
      // Ejemplo de respuesta Django: {"cmd":"SET_PESO:500"} o {"cmd":"CMD:STOP"}
      int pos_cmd = respuesta.indexOf("\"cmd\":");
      if (pos_cmd >= 0) {
        int inicio_cmd = respuesta.indexOf("\"", pos_cmd + 6);
        int fin_cmd = respuesta.indexOf("\"", inicio_cmd + 1);
        if (inicio_cmd >= 0 && fin_cmd > inicio_cmd) {
          String comando_extraido = respuesta.substring(inicio_cmd + 1, fin_cmd);
          Serial.print("Enviando comando pendiente al Mega: ");
          Serial.println(comando_extraido);
          SerialMega.println(comando_extraido);
        }
      }
    } else {
      Serial.printf("Fallo en peticion HTTPS: %s\n", http.errorToString(codigo_http).c_str());
    }
    http.end();
  }
}
