#include "header.h"

void setup() {
  /* Define las entradas y salidas de los pines */
  pinMode(pulso,OUTPUT); 
  pinMode(sentido,OUTPUT); 
  pinMode(son,OUTPUT); 
  pinMode(PE,INPUT);
  pinMode(isr_19,INPUT_PULLUP);
  pinMode(PULSADOR,INPUT);
  pinMode(POS0,INPUT);
  pinMode(AUX_IN1,INPUT);
  /* ------------------------------------------ */
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  /* Crea caracteres personalizados como: barra, flecha arriba y flecha abajo */
  lcd.createChar (0, pbar);
  lcd.createChar (1, flecha_sube);
  lcd.createChar (2, flecha_baja);
  /* ------------------------------------------------------------------------ */
  /* Imprime pantalla de inicio al prender la máquina */
  lcd.setCursor(3, 1);
  lcd.print("JACS MAQUINAS");
  delay(2500);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("DOSIFICADOR");
  lcd.setCursor(6, 2);
  lcd.print("DSL-500");
  /* ----------------------------------------------- */
  delay(2500);
  lcd.setCursor(0, 1);
  /* Carga los valores guardados en la EEPROM */
  cargar_valores();
  /* ---------------------------------------- */
  /* Activa el PCINT en el pin A15 */
  PCICR |= B00000100;   // PCINT2
  PCMSK2 |= B10000000;  // A15
  /* ---------------------------------------- */
}
void loop() {
  /* Imprime pantalla principal de funcionamiento de máquina */
  lcd.clear(); 
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("1)INICIAR     D)MENU");
  lcd.setCursor(0, 2);
  lcd.print("2)DOSIS (" + String(var_dosis) + "ml)");
  lcd.setCursor(0, 3);
  lcd.print("3)VELOCIDAD(" + String(var_velocidad_d) + "rpm)");
  /* ------------------------------------------------------- */
  switch(tec()){
      case '1':          
        iniciar();     
        break;
      case '2': 
        set_dosis();
        break;
      case '3':          
        set_velocidad();
        break;
      case '4':    
        set_pulsos();
        break;
      case '5':
        set_delay();
        break;
      case '6':          
        pos_ini();
        break;
      case 'D':
        opc_1();
        break;        
  }
}
char tec(){
  while(1){
    TECLA = teclado.getKey();
    if (TECLA){
      Serial.println(TECLA);
      return(TECLA);
    }
  }
}
boolean regresar(){
  /* -- Funcion para detener pulsos si tecla es "*" -- */
  if (TECLA != '*')
    TECLA = teclado.getKey();
  if (TECLA == '*'){       
      /* Imprime pantalla de detener máquina */
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("JACS MAQUINAS");
      lcd.setCursor(3, 3);
      lcd.print("Finalizando..."); 
      /* ----------------------------------- */
      delay(600); 
      return true;     
  } 
  else{
    return false;
  }
}
void cargar_valores(){ 
  EEPROM.get( 0, var_dosis );                     // dosis (ml)                                           *
  EEPROM.get( 10, diametro_embolo );              // diámetro del embolo (mm)                             *
  EEPROM.get( 20, var_paso );                     // paso de tornillo (mm)                                *
  EEPROM.get( 30, pulsos_rev );                   // pulsos x revolución                                  *
  EEPROM.get( 40, var_modo );                     // modo de trabajo (Manual = 1 o Automático = 2)        *
  EEPROM.get( 50, var_longitud );                 // no me acuerdo (by tono)          
  EEPROM.get( 60, var_velocidad_d );              // velocidad de descarga (rpm)                          *
  var_velocidad = (2000 - var_velocidad_d) + 40;  // velocidad en función de velocidad de descarga
  EEPROM.get( 70, var_delay );                    // delay en descarga                                    *
  EEPROM.get( 80, pulsos_dosis );                 // para calcular cuantos pulsos se necesita por dosis   *
  EEPROM.get( 90, var_error );                    // error                                                *
  EEPROM.get( 100, var_dosis_max );               // dosis máxima                                         *
  EEPROM.get( 110, var_delay_aut );               // delay en modo automático                             *
  EEPROM.get( 120, var_repetir );                 // repetir dosis                                        *
  EEPROM.get( 130, var_velocidad_c );             // velocidad de carga (rpm)                             *
  EEPROM.get( 140, var_delay_c );                 // delay en carga                                       *
  EEPROM.get( 150, var_velocidad_max );           // velocidad máxima                                     *
  EEPROM.get( 160, contador );                    // contador                                             *
}
ISR(PCINT2_vect){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("PARADA DE EMERGENCIA");
  lcd.setCursor(6, 2);
  lcd.print("ACTIVADA");
  /*while(PINK & B10000000){
  }*/
  delayMicroseconds(500);
  lcd.clear();
}