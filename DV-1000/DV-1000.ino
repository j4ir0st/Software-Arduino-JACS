#include "Header.h"

void setup() {
  /* Define las entradas y salidas de los pines */
  pinMode(fina,OUTPUT); 
  pinMode(gruesa,OUTPUT); 
  pinMode(m_abre,OUTPUT); 
  pinMode(m_cierra,OUTPUT); 
  /* ------------------------------------------ */
  Serial.begin(9600);
  cell.begin(50, 52);
  lcd.init();
  lcd.backlight();
  /* Crea caracteres personalizados como: barra, flecha arriba y flecha abajo */
  lcd.createChar (0, pbar);
  lcd.createChar (1, flecha_sube);
  lcd.createChar (2, flecha_baja);
  /* ------------------------------------------------------------------------ */
  /* Imprime pantalla de inicio al prender la máquina */
  lcd.setCursor(3, 1);
  lcd.print("JACS MAQUINAS");
  delay(1500);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("DOSIFICADOR");
  lcd.setCursor(6, 2);
  lcd.print("DV-1000");
  lcd.setCursor(11, 3);
  lcd.print("V2022.0.2");
  cargar_valores();
  delay(1500);
  /* ----------------------------------------------- */
  /* Imprime pantalla de descarga, libera el recipiente de pesado y realiza la calibración inicial */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(3, 3);
  lcd.print("DESCARGANDO...");
  descargar();
  delay(2500);
  calibracion_tara();
  /* --------------------------------------------------------------------------------------------- */
}
void loop() {
  /* Imprime pantalla principal de funcionamiento de máquina */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("1)INICIAR");
  lcd.setCursor(0, 2);
  lcd.print("2)PESO(" + String(s_peso) + "gr)");
  lcd.setCursor(0, 3);
  lcd.print("3)VF(" + String(v_fina) + "gr)");
  lcd.setCursor(14, 1);
  lcd.print("4)TARA");
  lcd.setCursor(14, 2);
  lcd.print("#)DESC");
  lcd.setCursor(14, 3);
  lcd.print("D)MENU");
  /* ------------------------------------------------------- */
  if (tec()){
    switch(TECLA){
      case '1':         
        iniciar();
        break;
      case '2':
        set_peso();
        break;
      case '3':
        v_fina_value();
        break;
      case '4':
        calibracion_tara();
        break;
      case '#':
        descargar();
        break;
      case 'D':
        opc1();
        break;
    }    
  }
}
char tec(){
  while(1){
    TECLA = teclado.getKey();
    if (TECLA){
      Serial.println(TECLA);
      return(TECLA);
    }
    /* Presionar el boton parada de emergancia descarga el producto (cambiar a interrupciones)*/
    if (digitalRead(PE) == 0 || digitalRead(pulsador) == 1)
      descargar();
    /* -------------------------------------------------------------------------------------- */            
  }
}
void cargar_valores(){ 
  EEPROM.get( 0, peso_ref );        // Peso referencial de calibración
  EEPROM.get( 10, set_scale );      // Asigna la escala
  EEPROM.get( 20, s_peso );         // Valor a pesar definido por set_peso
  EEPROM.get( 30, i_modo );         // Modo: 1=Automático 2=Manual
  EEPROM.get( 40, inercia );
  EEPROM.get( 50, d1 );
  EEPROM.get( 60, d2 );
  EEPROM.get( 70, d3 );
  EEPROM.get( 80, v_fina );         // Vibración Fina en gramos
  EEPROM.get( 90, error );
  EEPROM.get( 100, peso_max );
  EEPROM.get( 110, peso_min );
  EEPROM.get( 120, delay_aut );
  // EEPROM.get( 130, pulsador );   // Arreglar el set pin
  EEPROM.get( 140, contador );
  EEPROM.get( 150, t_ac1 );         // Tiempo de auto correccion 1
  EEPROM.get( 160, t_ac2 );         // Tiempo de auto correccion 2
  EEPROM.get( 170, t_ac3 );         // Tiempo de auto correccion 3
  EEPROM.get( 180, ac_modo );       // activa o desactiva la auto correccion
}