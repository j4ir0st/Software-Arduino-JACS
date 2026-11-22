#ifndef __Header_NS_GH__
#define __Header_NS_GH__

#include "LiquidCrystal_I2C.h"
#include "Keypad.h"
#include <EEPROM.h>
#include "ModbusMaster.h"

/* ========================================================================== */
/* CONFIGURACIÓN DEL BUS RS-485 MODBUS (CONTROLADORES DE TEMPERATURA)        */
/* ========================================================================== */
#define PIN_MAX485_DE      3    // Pin de control Driver Enable del módulo MAX485
#define PIN_MAX485_RE_NEG  2    // Pin de control Receiver Enable del módulo MAX485
ModbusMaster nodo_modbus;       // Objeto Modbus para comunicación con pirómetros

/* ========================================================================== */
/* CONFIGURACIÓN DEL TECLADO MATRICIAL (4x4)                                   */
/* ========================================================================== */
const byte FILAS = 4;                               // Número de filas del teclado
const byte COLUMNAS = 4;                            // Número de columnas del teclado
char teclas[FILAS][COLUMNAS] = {                    // Distribución de caracteres en las teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pines_filas[FILAS] = {37, 35, 33, 31};         // Pines Arduino conectados a las filas
byte pines_columnas[COLUMNAS] = {29, 27, 25, 23};   // Pines Arduino conectados a las columnas
Keypad teclado = Keypad(makeKeymap(teclas), pines_filas, pines_columnas, FILAS, COLUMNAS);
char TECLA;                                         // Almacena la última tecla física procesada

/* ========================================================================== */
/* CONFIGURACIÓN DE PANTALLA LCD I2C                                         */
/* ========================================================================== */
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Carácter personalizado: Barra de progreso llena
byte barra_progreso[8] = {
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};

// Carácter personalizado: Flecha que apunta hacia arriba
byte flecha_sube[8] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};

// Carácter personalizado: Flecha que apunta hacia abajo
byte flecha_baja[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100,
};

/* ========================================================================== */
/* ASIGNACIÓN DE PINES DE ACTUADORES Y SALIDAS DE RELÉ                       */
/* ========================================================================== */
int pin_mordazas = 10;          // Salida relé: Mordazas de sellado horizontal y corte
int pin_arrastre = 6;           // Salida relé/driver: Motor de arrastre de película (film)
int pin_actuador = 9;           // Salida relé: Actuador de corte / fechador auxiliar
int pin_aux1 = 11;              // Salida relé auxiliar 1 (ej. sellador vertical / soplado)
int pin_aux2 = 12;              // Salida relé auxiliar 2
int pin_aux3 = 13;              // Salida relé auxiliar 3

/* ========================================================================== */
/* ASIGNACIÓN DE PINES DE SENSORES Y ENTRADAS DIGITALES                      */
/* ========================================================================== */
int pin_sw_tolvas = A0;         // Entrada digital: Señal de tolvas DV-1000 listas (handshake físico)
int pin_fc_mordazas = A1;       // Entrada digital: Final de carrera de mordazas abiertas
int pin_fc_aux = A2;            // Entrada digital: Sensor de posición auxiliar
int pin_parada_emergencia = A3; // Entrada digital: Botón físico de Parada de Emergencia (PE)
int pin_sensor_taca = A4;       // Entrada digital: Sensor óptico de taco / fotomarca de corte
int pin_arrastre_manual = A5;   // Entrada digital: Pulsador de arrastre manual externo

/* ========================================================================== */
/* PARÁMETROS DE CONFIGURACIÓN Y TIEMPOS DE OPERACIÓN                        */
/* ========================================================================== */
int tiempo_sellado = 1000;      // Tiempo de prensado y sellado de mordazas (en ms)
int tiempo_arrastre = 400;      // Tiempo de arrastre de film por temporizador (en ms)
int tiempo_mordaza_cierra = 400;// Tiempo de activación del pistón de cierre de mordaza
int tiempo_mordaza_abre = 400;  // Tiempo de retorno del pistón de mordaza
int usar_fc_mordaza = 0;        // 1 = Espera fin de carrera; 0 = Solo por tiempo
int usar_sensor_taca = 0;       // 1 = Arrastre hasta detectar taco óptico; 0 = Por tiempo fijo
int secuencia_operacion = 0;    // 0 = Sella -> Descarga tolva -> Arrastra; 1 = Sella+Descarga paralelo
long contador_bolsas = 0;       // Contador acumulado de paquetes/bolsas producidas
int clave_acceso = 1234;        // Clave de acceso al menú de configuración local
int tipo_maquina = 0;           // Variante de máquina (0 = Estándar, 1 = Especial)

/* ========================================================================== */
/* VARIABLES DE CONTROL DE TEMPERATURAS (RS-485 MODBUS)                      */
/* ========================================================================== */
int temp_actual_sup_izq = 0;    // Temperatura actual mordaza superior izquierda (ID 7)
int temp_actual_sup_der = 0;    // Temperatura actual mordaza superior derecha (ID 8)
int temp_actual_inf_ext = 0;    // Temperatura actual mordaza inferior externa (ID 9)
int temp_actual_inf_int = 0;    // Temperatura actual mordaza inferior interna (ID 10)

int temp_consigna_sup_izq = 150;// Temperatura deseada superior izquierda
int temp_consigna_sup_der = 150;// Temperatura deseada superior derecha
int temp_consigna_inf_ext = 150;// Temperatura deseada inferior externa
int temp_consigna_inf_int = 150;// Temperatura deseada inferior interna

boolean calefaccion_activa = false; // Estado general de los calentadores de sellado

/* ========================================================================== */
/* VARIABLES DE ESTADO Y TELEMETRÍA EN TIEMPO REAL                           */
/* ========================================================================== */
double tiempo_ciclo_inicio = 0; // Marca de tiempo de inicio de ciclo para cálculo de bolsas/min
double tiempo_ciclo_fin = 0;    // Marca de tiempo de fin de ciclo
float bolsas_por_minuto = 0.0;  // Producción calculada en bolsas por minuto (BPM)
String estado_maquina = "ESPERA"; // Estado reportado a VB.NET ("ESPERA", "ENVASANDO", "SELLANDO", etc.)
boolean envasando_activo = false; // Bandera de ciclo continuo de envasado
boolean solicitud_detener = false;// Bandera de detención inmediata

/* ========================================================================== */
/* IDENTIFICACIÓN Y COMUNICACIÓN SERIE USB PARA CONTROL DESDE VISUAL BASIC    */
/* ========================================================================== */
String buffer_recepcion_serie = "";             // Búfer de caracteres recibidos por USB
unsigned long tiempo_ultimo_envio_serie = 0;    // Control de tiempo para telemetría no bloqueante

#endif
