#ifndef __Header_DV1000__
#define __Header_DV1000__

#include "LiquidCrystal_I2C.h"
#include "Keypad.h"
#include "HX711.h"
#include <EEPROM.h>

/* ========================================================================== *
/
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
char TECLA;                                         // Almacena la última tecla física o comando procesado

/* ========================================================================== */
/* CONFIGURACIÓN DE PANTALLA LCD I2C Y CARACTERES PERSONALIZADOS             */
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
/* VARIABLES DE CONTROL DE PESAJE Y CALIBRACIÓN                               */
/* ========================================================================== */
long peso_ref = 0;              // Peso referencial usado durante la calibración
float escala_calibracion = 0;   // Factor de escala calculado de la celda de carga
int peso_max = 0;               // Límite máximo de peso permitido
int peso_min = 0;               // Límite mínimo de peso permitido

long peso = 0;                  // Lectura actual de peso en gramos
int peso_vf = 0;                // Umbral para corte de vibración fina
int s_peso = 0;                 // Peso objetivo configurado para dosificar
int i_modo = 0;                 // Modo de operación: 1 = Automático, 2 = Manual
int ac_modo = 0;                // Modo autocorrección: 1 = Activo, 0 = Inactivo
int inercia = 0;                // Compensación de inercia de caída de material
int error = 0;                  // Margen de error aceptable en gramos
int peso_vg = 0;                // Umbral para corte de vibración gruesa

/* ========================================================================== */
/* TIEMPOS Y RETARDOS DE OPERACIÓN (en milisegundos)                          */
/* ========================================================================== */
int d1 = 0;                     // Retardo 1: Apertura de compuerta de descarga
int d2 = 0;                     // Retardo 2: Tiempo de vaciado en descarga
int d3 = 0;                     // Retardo 3: Cierre de compuerta de descarga
int tiempo_descarga = 2000;     // Tiempo de apertura del pistón neumático en descarga (default 2000 ms)
int t_ac1 = 0;                  // Tiempo de pausa en autocorrección
int t_ac2 = 0;                  // Tiempo de activación de pulsos en autocorrección
int t_ac3 = 0;                  // Tiempo de estabilización en autocorrección
int v_fina = 0;                 // Rango de vibración fina en gramos
int delay_aut = 0;              // Retardo de espera en modo automático antes de descargar

boolean listo = false;          // Bandera de ciclo completado

/* ========================================================================== */
/* ASIGNACIÓN DE PINES DE ACTUADORES Y ENTRADAS DIGITALES                     */
/* ========================================================================== */
int fina = 7;                   // Salida: Vibrador fino
int gruesa = 8;                 // Salida: Vibrador grueso
int m_abre = 9;                 // Salida: Motor/Pistón apertura compuerta
int m_cierra = 10;              // Salida: Motor/Pistón cierre compuerta
int PE = A3;                    // Entrada digital: Pulsador de Parada de Emergencia
int pulsador = A0;              // Entrada digital: Pulsador manual de descarga
const float e = 271828;         // Constante auxiliar
int estado = 0;                 // Estado del actuador / compuerta
long contador = 0;              // Contador total acumulado de descargas realizadas
long var_cont = 0;              // Contador de ciclo actual o temporal

/* ========================================================================== */
/* SENSOR DE PESO: CELDA DE CARGA Y AMPLIFICADOR HX711                        */
/* ========================================================================== */
const byte PIN_HX711_DAT = 50;                  // Pin DOUT / DAT (Datos) del amplificador HX711
const byte PIN_HX711_CLK = 52;                  // Pin SCK / CLK (Reloj) del amplificador HX711
HX711 celda(PIN_HX711_DAT, PIN_HX711_CLK);
/* ========================================================================== */
/* IDENTIFICACIÓN Y COMUNICACIÓN SERIE USB PARA CONTROL DESDE VISUAL BASIC    */
/* ========================================================================== */
int id_dosificador = 1;                         // Identificador único de este dosificador (para múltiples tolvas)
String buffer_recepcion_serie = "";             // Búfer para almacenar caracteres recibidos por USB
unsigned long tiempo_ultimo_envio_serie = 0;    // Control de tiempo para telemetría no bloqueante (millis)
String estado_dosificador = "ESPERA";           // Estado actual reportado a Visual Basic ("ESPERA", "GRUESA", "FINA", etc.)
boolean solicitud_detener_remoto = false;        // Bandera de parada ordenada por comando USB
boolean conexion_pc_activa = false;             // Bandera: true solo cuando la PC (.NET) inicia comunicación activa

#endif
