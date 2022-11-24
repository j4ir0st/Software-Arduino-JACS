/* MENÚ RESET DE FÁBRICA */
void opc9(){
ini:  
  /* Imprime pantalla de menú reset de fábrica */
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("RESET DE FABRICA");
  lcd.setCursor(0, 1);
  lcd.print("1)RESTAURAR");
  lcd.setCursor(0, 2);
  lcd.print("2)GUARDAR");
  lcd.setCursor(14, 1);
  lcd.print("3)RST");
  lcd.setCursor(0, 3);
  lcd.print("*)Inicio");
  lcd.setCursor(19, 0);
  lcd.print("A");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  lcd.setCursor(19, 3);
  lcd.print("B");
  /* -------------------------------------------- */
  switch(tec()){
    case '1':
      if (msgbox_yes_no("RESTAURAR DATOS") == 1){
        lcd.clear();
        lcd.setCursor(3, 2);
        lcd.print("restaurando...");
        restaurar();
        delay(2000); 
        lcd.setCursor(3, 2);
        lcd.print("Restauración lista");
        delay(500);
      }
      goto ini;
    case '2':
      if (msgbox_yes_no("GUARDAR DATOS") == 1){
        guardar();
        lcd.clear();
        lcd.setCursor(4, 2);
        lcd.print("Guardado!");
        delay(1000);
      }
      goto ini;
    case '3':
      if (msgbox_yes_no("RESET DE FABRICA") == 1){
        lcd.clear();
        lcd.setCursor(3, 2);
        lcd.print("reseteando...");  
        reset_valores();
        delay(2000);
        lcd.clear();
        lcd.setCursor(4, 2);
        lcd.print("cargando...");  
        cargar_valores();
        delay(2000); 
        lcd.setCursor(3, 2);
        lcd.print("Reseteo listo");
        delay(500);
        return;
      }
      goto ini;
    case 'A':
      opc8();
      return;  
    case 'B':
      opc1();
      return;
    case '*':
      return;
    default:
      goto ini;
  }   
}
void reset_valores(){ 
  EEPROM.put( 0, 500 );         // Peso referencial de calibración
  EEPROM.put( 10, 0 );          // Asigna la escala
  EEPROM.put( 20, 500 );        // Valor a pesar definido por set_peso
  EEPROM.put( 30, 2 );          // Modo: 1=Automático 2=Manual
  EEPROM.put( 40, 2 );
  EEPROM.put( 50, 400 );
  EEPROM.put( 60, 400 );
  EEPROM.put( 70, 400 );
  EEPROM.put( 80, 20 );         // Vibración Fina en gramos
  EEPROM.put( 90, 0 );
  EEPROM.put( 100, 1000 );
  EEPROM.put( 110, 0 );
  EEPROM.put( 120, 1000 );
  //EEPROM.put( 130, A0 );        // pulsador
  EEPROM.put( 150, 200 );         // Tiempo de auto correccion 1
  EEPROM.put( 160, 200 );         // Tiempo de auto correccion 2
  EEPROM.put( 170, 200 );         // Tiempo de auto correccion 3
  EEPROM.put( 180, 0 );       // 1=activa, 0=desactiva la auto correccion
}
void guardar(){ 
  EEPROM.put( 200, peso_ref );        // Peso referencial de calibración
  EEPROM.put( 210, set_scale );      // Asigna la escala
  EEPROM.put( 220, s_peso );         // Valor a pesar definido por set_peso
  EEPROM.put( 230, i_modo );         // Modo: 1=Automático 2=Manual
  EEPROM.put( 240, inercia );
  EEPROM.put( 250, d1 );
  EEPROM.put( 260, d2 );
  EEPROM.put( 270, d3 );
  EEPROM.put( 280, v_fina );         // Vibración Fina en gramos
  EEPROM.put( 290, error );
  EEPROM.put( 300, peso_max );
  EEPROM.put( 310, peso_min );
  EEPROM.put( 320, delay_aut );
  //EEPROM.put( 330, pulsador );
  EEPROM.put( 340, contador );
  EEPROM.put( 350, t_ac1 );         // Tiempo de auto correccion 1
  EEPROM.put( 360, t_ac2 );         // Tiempo de auto correccion 2
  EEPROM.put( 370, t_ac3 );         // Tiempo de auto correccion 3
  EEPROM.put( 380, ac_modo );       // 1=activa, 0=desactiva la auto correccion
}
void restaurar(){
  EEPROM.get( 200, peso_ref );        // Peso referencial de calibración
  EEPROM.get( 210, set_scale );      // Asigna la escala
  EEPROM.get( 220, s_peso );         // Valor a pesar definido por set_peso
  EEPROM.get( 230, i_modo );         // Modo: 1=Automático 2=Manual
  EEPROM.get( 240, inercia );
  EEPROM.get( 250, d1 );
  EEPROM.get( 260, d2 );
  EEPROM.get( 270, d3 );
  EEPROM.get( 280, v_fina );         // Vibración Fina en gramos
  EEPROM.get( 290, error );
  EEPROM.get( 300, peso_max );
  EEPROM.get( 310, peso_min );
  EEPROM.get( 320, delay_aut );
  //EEPROM.get( 330, pulsador );
  EEPROM.get( 340, contador );
  EEPROM.get( 350, t_ac1 );         // Tiempo de auto correccion 1
  EEPROM.get( 360, t_ac2 );         // Tiempo de auto correccion 2
  EEPROM.get( 370, t_ac3 );         // Tiempo de auto correccion 3
  EEPROM.get( 380, ac_modo );       // 1=activa, 0=desactiva la auto correccion
}
int msgbox_yes_no(String pregunta){
ini:
  lcd.clear(); 
  lcd.setCursor(10 - ((pregunta.length() / 2)), 0);    
  lcd.print(pregunta);
  lcd.setCursor(8, 1);
  lcd.print("1)SI");
  lcd.setCursor(8, 2);
  lcd.print("2)NO");
  lcd.setCursor(0, 3);       
  lcd.print("*)regresar");    
  switch(tec()){        
    case '1':      
      return(1);
    case '2':
      return(0);
    case '*':        
      return(-1);
    default:
      goto ini;
  }  
}