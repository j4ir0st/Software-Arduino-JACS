/* ========================================================================== */
/* MÓDULO DE CONECTIVIDAD IOT, TELEMETRÍA REMOTA Y EEPROM EXTERNA            */
/* Proyecto: Dosificador Industrial Automático DV-1000                        */
/* ========================================================================== */
/*
 * GUÍA DE COMPONENTES DE HARDWARE PARA CONECTIVIDAD A INTERNET:
 * 
 * 1. MÓDULO RECOMENDADO (Gateway WiFi / Nube):
 *    - ESP32 NodeMCU DevKit V1 (30 o 38 pines) [RECOMENDADO]
 *      O en su defecto: ESP8266 NodeMCU V3 / Wemos D1 Mini.
 *    - Razón: Cuenta con procesador independiente, antena WiFi integrada y
 *      capacidad de negociación SSL/TLS (HTTPS) para comunicarse directamente
 *      con la API en Django (desplegada en Vercel) y la base de datos Supabase.
 *    - Precio de referencia: ~$4 - $6 USD.
 * 
 * 2. ALTERNATIVA CABLEADA (Ethernet Industrial):
 *    - Módulo Ethernet USR-TCP232 (Conversor UART a Ethernet RJ45) o W5500.
 *    - Ideal si la fábrica o planta cuenta con cable de red estructurado RJ45.
 * 
 * 3. ALTERNATIVA BLUETOOTH (Control local en planta con tablet/celular):
 *    - Módulo Bluetooth HC-05 o HC-06 conectado a Serial1 (9600 o 38400 baudios).
 * 
 * 4. MEMORIA EEPROM EXTERNA PARA NÚMERO DE SERIE DE FÁBRICA:
 *    - Chip I2C: 24LC256, 24C16, 24C08 o 24C04 (formato DIP-8 o SOIC-8).
 *    - Dirección I2C típica: 0x50 (con pines A0, A1, A2 conectados a GND).
 *    - Si la EEPROM no está instalada o aún no tiene datos grabados, este código
 *      cuenta con fallback automático hacia la EEPROM interna del ATmega2560.
 * 
 * ==========================================================================
 * DIAGRAMA DE CONEXIÓN FÍSICA CON ARDUINO MEGA 2560:
 * 
 * [ARDUINO MEGA 2560]                  [MÓDULO ESP32 / GATEWAY]
 *  - Pin 18 (TX1) ------[R 1kΩ]--------> Pin 16 (RX2)  *(Divisor resistivo 5V a 3.3V)*
 *                               |
 *                            [R 2kΩ]
 *                               |
 *                              GND
 *  - Pin 19 (RX1) <---------------------- Pin 17 (TX2)  *(Conexión directa: 3.3V es HIGH)*
 *  - GND          ----------------------> GND común
 *  - 5V / Externa ----------------------> VIN (Alimentación 5V regulada)
 * 
 * [ARDUINO MEGA 2560]                  [EEPROM EXTERNA 24Cxx]
 *  - Pin 20 (SDA) ----------------------> Pin 5 (SDA)  *(con resistencia pull-up 4.7k a 5V)*
 *  - Pin 21 (SCL) ----------------------> Pin 6 (SCL)  *(con resistencia pull-up 4.7k a 5V)*
 *  - 5V           ----------------------> Pin 8 (VCC)
 *  - GND          ----------------------> Pines 1, 2, 3, 4, 7 (A0, A1, A2, VSS, WP)
 * ==========================================================================
 */

#include "Header.h"
#include <Wire.h>

// Dirección I2C base para memorias EEPROM externas serie 24Cxx (0x50 a 0x57)
const byte DIRECCION_I2C_EEPROM_EXTERNA = 0x50;

/* ========================================================================== */
/* INICIALIZACIÓN DE CONECTIVIDAD IOT Y SERIAL1                               */
/* ========================================================================== */
void inicializar_iot() {
  // Inicializa el puerto hardware Serial1 para el módulo inalámbrico (ESP32/Ethernet/Bluetooth)
  Serial1.begin(115200);

  // Inicializa el bus I2C para periféricos y memoria externa si no estaba iniciado
  Wire.begin();

  // Lee el número de serie único grabado en hardware
  leer_numero_serie_hardware();

  // Mensaje de arranque por el canal IoT
  Serial1.println();
  Serial1.print(F("{\"boot\":\"DV1000\",\"sn\":\""));
  Serial1.print(sn_maquina);
  Serial1.println(F("\",\"ready\":true}"));
}

/* ========================================================================== */
/* LECTURA DEL NÚMERO DE SERIE ÚNICO DE LA MÁQUINA                             */
/* Intenta leer desde la EEPROM I2C externa; si no responde, usa EEPROM interna */
/* ========================================================================== */
void leer_numero_serie_hardware() {
  boolean eeprom_externa_detectada = false;

  // 1. Probar presencia de la EEPROM externa en el bus I2C
  Wire.beginTransmission(DIRECCION_I2C_EEPROM_EXTERNA);
  if (Wire.endTransmission() == 0) {
    // La memoria externa respondió al llamado I2C
    Wire.beginTransmission(DIRECCION_I2C_EEPROM_EXTERNA);
    Wire.write((byte)0x00); // Dirección de memoria alta / offset 0
    Wire.write((byte)0x00); // Dirección de memoria baja
    if (Wire.endTransmission() == 0) {
      Wire.requestFrom((uint8_t)DIRECCION_I2C_EEPROM_EXTERNA, (uint8_t)16);
      int indice = 0;
      char buffer_sn[17];
      while (Wire.available() && indice < 16) {
        char c = (char)Wire.read();
        // Verificar que sean caracteres imprimibles válidos
        if (c >= 32 && c <= 126) {
          buffer_sn[indice++] = c;
        } else {
          break;
        }
      }
      buffer_sn[indice] = '\0';

      if (indice >= 3) { // Si contiene al menos 3 caracteres válidos
        sn_maquina = String(buffer_sn);
        eeprom_externa_detectada = true;
      }
    }
  }

  // 2. Si no hay EEPROM externa o está vacía, leer de EEPROM interna (dirección 200..219)
  if (!eeprom_externa_detectada) {
    char sn_interno[17];
    boolean tiene_datos_validos = true;
    for (int i = 0; i < 16; i++) {
      char c = (char)EEPROM.read(200 + i);
      if (c >= 32 && c <= 126) {
        sn_interno[i] = c;
      } else if (c == '\0' && i > 0) {
        sn_interno[i] = '\0';
        break;
      } else {
        tiene_datos_validos = false;
        break;
      }
    }
    sn_interno[16] = '\0';

    if (tiene_datos_validos && strlen(sn_interno) >= 3) {
      sn_maquina = String(sn_interno);
    } else {
      // Valor de fábrica por defecto identificado por el ID de la máquina
      sn_maquina = "DV1000-" + String(id_dosificador < 10 ? "00" : "0") + String(id_dosificador);
      // Graba el valor de fábrica en la EEPROM interna para persistencia
      for (unsigned int i = 0; i < sn_maquina.length() && i < 16; i++) {
        EEPROM.update(200 + i, sn_maquina[i]);
      }
      EEPROM.update(200 + sn_maquina.length(), '\0');
    }
  }
}

/* ========================================================================== */
/* RECEPTOR DE COMANDOS DESDE LA NUBE / PORTAL WEB (SERIAL1)                  */
/* No bloqueante: procesa órdenes de la web mientras la máquina trabaja       */
/* ========================================================================== */
char procesar_serial_iot() {
  while (Serial1.available() > 0) {
    char caracter = (char)Serial1.read();

    if (caracter == '\n' || caracter == '\r') {
      buffer_recepcion_iot.trim();
      if (buffer_recepcion_iot.length() > 0) {
        char accion = interpretar_comando_iot(buffer_recepcion_iot);
        buffer_recepcion_iot = "";
        if (accion != 0) {
          return accion;
        }
      }
    } else {
      if (buffer_recepcion_iot.length() < 96) {
        buffer_recepcion_iot += caracter;
      }
    }
  }
  return 0;
}

/* ========================================================================== */
/* INTÉRPRETE DE COMANDOS IOT RECIBIDOS DESDE LA API EN DJANGO                */
/* Permite control remoto completo: cambio de pesos, parada, inicio, descarga  */
/* ========================================================================== */
char interpretar_comando_iot(String comando) {
  comando.toUpperCase();

  // 1. Comando INICIAR ciclo de dosificación
  if (comando == "CMD:INICIAR" || comando == "CMD:START") {
    Serial1.println(F("{\"status\":\"OK\",\"cmd\":\"INICIAR\"}"));
    return '1';
  }

  // 2. Comando DETENER ciclo
  if (comando == "CMD:DETENER" || comando == "CMD:STOP") {
    solicitud_detener_remoto = true;
    Serial1.println(F("{\"status\":\"OK\",\"cmd\":\"DETENER\"}"));
    return '*';
  }

  // 3. Comando TARA
  if (comando == "CMD:TARA" || comando == "CMD:TARE") {
    Serial1.println(F("{\"status\":\"OK\",\"cmd\":\"TARA\"}"));
    return '4';
  }

  // 4. Comando DESCARGAR pistón neumático
  if (comando == "CMD:DESC" || comando == "CMD:DESCARGAR") {
    Serial1.println(F("{\"status\":\"OK\",\"cmd\":\"DESCARGAR\"}"));
    return '#';
  }

  // 5. Consulta de Telemetría bajo demanda
  if (comando == "GET:STATUS" || comando == "PING") {
    enviar_telemetria_iot_json();
    return 0;
  }

  // 6. Configurar Peso Objetivo remotamente (ejemplo: SET_PESO:500)
  if (comando.startsWith("SET_PESO:") || comando.startsWith("PESO:")) {
    int sep = comando.indexOf(':');
    int nuevo_peso = comando.substring(sep + 1).toInt();
    if (nuevo_peso >= peso_min && (peso_max == 0 || nuevo_peso <= peso_max)) {
      s_peso = nuevo_peso;
      EEPROM.put(20, s_peso);
      Serial1.print(F("{\"status\":\"OK\",\"param\":\"PESO\",\"val\":"));
      Serial1.print(s_peso);
      Serial1.println(F("}"));
      // Refresca la pantalla física
      lcd.setCursor(0, 2);
      lcd.print("2)PESO(" + String(s_peso) + "gr)   ");
    } else {
      Serial1.println(F("{\"status\":\"ERR\",\"msg\":\"PESO_FUERA_DE_RANGO\"}"));
    }
    return 0;
  }

  // 7. Configurar Vibración Fina remotamente (ejemplo: SET_VF:30)
  if (comando.startsWith("SET_VF:") || comando.startsWith("VFINA:")) {
    int sep = comando.indexOf(':');
    int nueva_vf = comando.substring(sep + 1).toInt();
    if (nueva_vf >= 0 && nueva_vf <= 1000) {
      v_fina = nueva_vf;
      EEPROM.put(80, v_fina);
      Serial1.print(F("{\"status\":\"OK\",\"param\":\"VFINA\",\"val\":"));
      Serial1.print(v_fina);
      Serial1.println(F("}"));
      lcd.setCursor(0, 3);
      lcd.print("3)VF(" + String(v_fina) + "gr)   ");
    } else {
      Serial1.println(F("{\"status\":\"ERR\",\"msg\":\"VF_INVALIDA\"}"));
    }
    return 0;
  }

  // 8. Configurar Tiempo de Descarga del pistón remotamente (ejemplo: SET_TDESC:2000)
  if (comando.startsWith("SET_TDESC:") || comando.startsWith("TDESC:")) {
    int sep = comando.indexOf(':');
    int nuevo_td = comando.substring(sep + 1).toInt();
    if (nuevo_td >= 100 && nuevo_td <= 30000) {
      tiempo_descarga = nuevo_td;
      d2 = tiempo_descarga;
      EEPROM.put(60, tiempo_descarga);
      Serial1.print(F("{\"status\":\"OK\",\"param\":\"TDESC\",\"val\":"));
      Serial1.print(tiempo_descarga);
      Serial1.println(F("}"));
    } else {
      Serial1.println(F("{\"status\":\"ERR\",\"msg\":\"TDESC_INVALIDO\"}"));
    }
    return 0;
  }

  // 9. Configurar Inercia remotamente (ejemplo: SET_INER:5)
  if (comando.startsWith("SET_INER:") || comando.startsWith("INERCIA:")) {
    int sep = comando.indexOf(':');
    inercia = comando.substring(sep + 1).toInt();
    EEPROM.put(40, inercia);
    Serial1.print(F("{\"status\":\"OK\",\"param\":\"INERCIA\",\"val\":"));
    Serial1.print(inercia);
    Serial1.println(F("}"));
    return 0;
  }

  // Comando no reconocido
  Serial1.print(F("{\"status\":\"ERR\",\"msg\":\"COMANDO_DESCONOCIDO\",\"cmd\":\""));
  Serial1.print(comando);
  Serial1.println(F("\"}"));
  return 0;
}

/* ========================================================================== */
/* EMISIÓN DE TELEMETRÍA JSON COMPACTA HACIA LA NUBE (SUPABASE / VERCEL)      */
/* ========================================================================== */
void enviar_telemetria_iot_json() {
  Serial1.print(F("{\"sn\":\""));
  Serial1.print(sn_maquina);
  Serial1.print(F("\",\"id\":"));
  Serial1.print(id_dosificador);
  Serial1.print(F(",\"st\":\""));
  Serial1.print(estado_dosificador);
  Serial1.print(F("\",\"p\":"));
  Serial1.print(roundf(peso));
  Serial1.print(F(",\"obj\":"));
  Serial1.print(s_peso);
  Serial1.print(F(",\"vf\":"));
  Serial1.print(v_fina);
  Serial1.print(F(",\"iner\":"));
  Serial1.print(inercia);
  Serial1.print(F(",\"td\":"));
  Serial1.print(tiempo_descarga);
  Serial1.print(F(",\"tot\":"));
  Serial1.print(contador);
  Serial1.print(F(",\"pe\":"));
  Serial1.print(digitalRead(PE) == 0 ? 1 : 0); // Estado de parada de emergencia
  Serial1.println(F("}"));
}

/* ========================================================================== */
/* ENVÍO PERIÓDICO NO BLOQUEANTE (HEARTBEAT IOT)                              */
/* ========================================================================== */
void enviar_telemetria_iot_periodica(String nuevo_estado, unsigned long intervalo_ms) {
  estado_dosificador = nuevo_estado;
  unsigned long tiempo_actual = millis();
  if (tiempo_actual - tiempo_ultimo_envio_iot >= intervalo_ms) {
    tiempo_ultimo_envio_iot = tiempo_actual;
    enviar_telemetria_iot_json();
  }
}

/* ========================================================================== */
/* EVENTO INMEDIATO DE DESCARGA COMPLETADA (PARA HISTORIAL EN BASE DE DATOS) */
/* ========================================================================== */
void enviar_evento_descarga_iot() {
  Serial1.print(F("{\"event\":\"DESCARGA\",\"sn\":\""));
  Serial1.print(sn_maquina);
  Serial1.print(F("\",\"id\":"));
  Serial1.print(id_dosificador);
  Serial1.print(F(",\"peso_final\":"));
  Serial1.print(roundf(peso));
  Serial1.print(F(",\"obj\":"));
  Serial1.print(s_peso);
  Serial1.print(F(",\"error\":"));
  Serial1.print(roundf(peso) - s_peso);
  Serial1.print(F(",\"tot\":"));
  Serial1.print(contador);
  Serial1.println(F("}"));
}
