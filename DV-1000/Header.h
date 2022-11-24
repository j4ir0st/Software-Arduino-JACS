#ifndef __Header_DV1000__
#define __Header_DV1000__

#include "HX711.h"
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

const byte FILAS = 4;             // define numero de filas
const byte COLUMNAS = 4;          // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {37,35,33,31};       // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] ={29,27,25,23} ; // pines correspondientes a las columnas
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto
char TECLA;                                   // almacena la tecla presionada

LiquidCrystal_I2C lcd(0x27,20,4);
byte pbar[8] = {
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};
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
//valores de pesado-------------------------------
long peso_ref = 0;          // Peso referencial de calibración
float set_scale = 0;        // Asigna la escala
int peso_max = 0;
int peso_min = 0;
//-----------------------------------------------
long peso = 0;
int peso_vf = 0;
int s_peso = 0;             // Valor a pesar definido por set_peso
int i_modo = 0;             // define el modo: 1 = Automatico, 2 = Manual
int ac_modo = 0;            // 1=activa, 0=desactiva la auto correccion
int inercia = 0;
int error = 0;
int peso_vg = 0;

int d1 = 0;                 // Delay 1
int d2 = 0;                 // Delay 2
int d3 = 0;                 // Delay 3
int t_ac1 = 0;              // Tiempo de auto correccion 1
int t_ac2 = 0;              // Tiempo de auto correccion 2
int t_ac3 = 0;              // Tiempo de auto correccion 3
int v_fina = 0;             // Vibración Fina en gramos
int delay_aut = 0;          // Delay en modo Automatico

boolean listo = false;

int fina = 7;
int gruesa = 8;
int m_abre = 9;
int m_cierra = 10;
int PE = A3;                // Parada de Emergencia
int pulsador = A0;          // Pulsador de Descarga
const float e = 271828;
int estado = 0;
long contador = 0;
long var_cont = 0;

HX711 cell;

#endif