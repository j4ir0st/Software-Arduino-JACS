/* MENÚ CALIBRACIÓN */
void opc1(){
ini:
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("CALIBRACION");
  lcd.setCursor(0, 1);
  lcd.print("1)CALIBRAR");
  lcd.setCursor(0, 2);
  lcd.print("2)INER(" + String(inercia) + "gr)");
  lcd.setCursor(13, 1);
  lcd.print("3)TARA");
  lcd.setCursor(13, 2);
  lcd.print("4)CELD");
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
  if (tec()){
    switch(TECLA){
      case '*':  
        return;
      case '1':
        calibracion_avanzada();
        goto ini;
      case '2':
        set_inercia();
        goto ini;
      case '3':
        descargar();
        calibracion_tara();
        goto ini;
      case '4':
        cell_read();
        goto ini;
      case 'A':
        opc9();
        return;
      case 'B':
        opc2();
        return;
      default:
        goto ini;
    }    
  } 
}
void set_inercia(){
  inercia = input_int("INERCIA (" + String(inercia) + ")", 0, 100, "gr");
  if (inercia != -1){
    EEPROM.put( 40, inercia );
  } 
  else{
    EEPROM.get( 40, inercia );  
  }
}
void cell_read(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lectura de la");
  lcd.setCursor(0, 1);
  lcd.print("Celda de Carga:");
  lcd.setCursor(0, 3);
  lcd.print("*)Inicio");
  while(TECLA != '*'){
    TECLA = teclado.getKey();
    lcd.setCursor(6, 2);    
    lcd.print("          ");
    lcd.setCursor(6, 2);
    lcd.print(cell.read());
    delay(100);
  }
}
void set_error(){
  error = input_int("INGRESE ERROR (" + String(error) + ")", 0, 100, "gr");
  if (error != -1){
    EEPROM.put( 90, error );
  } 
  else{
    EEPROM.get( 90, error );  
  }
}
