#ifndef HEADER_H
#define HEADER_H

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>

char TECLA;                                     // almacena la tecla presionada
const byte FILAS = 4;                           // define numero de filas
const byte COLUMNAS = 4;                        // define numero de columnas
char keys[FILAS][COLUMNAS] = {                  // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {37,35,33,31};           // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] ={29,27,25,23} ;     // pines correspondientes a las columnas
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);    // crea objeto

const int rs = 49, en = 47, d4 = 45, d5 =43, d6 = 41, d7 = 39;
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

int var_cont;
int var_dosis;            // Dosis en ml
int var_repetir;          // Repetir Dosis
int var_dosis_max;
double var_error;
int diametro_embolo;
double diametro_embolo1;
double var_paso;
double var_paso1;
int pulsos_rev;
int var_modo;
double var_longitud;
long pulsos_dosis;
int var_velocidad;
int var_velocidad_d;
int var_velocidad_c;
int var_velocidad_max;
double var_delay;
double var_delay_c;
int var_delay_aut;
long cont;
const float pi = 3.1416;
long contador;

int sentido = 7;    //Sentido del servo
int son = 8;        //Servo On
int pulso = 9;
int isr_19 = A15;   // interupcion cuando se pulsa el bit 19
int AUX_IN1 = A1;   //S_MOR
int PE = A8;        //Parada de Emergencia
int POS0 = A4;      //TACA
int PULSADOR = A8;  //SW_AR

#endif