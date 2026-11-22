/* MENÚ DESCARGA */
void opc3(){
ini:
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("DESCARGA");
  lcd.setCursor(0, 1);
  lcd.print("1)D1:" + String(d1));
  lcd.setCursor(0, 2);
  lcd.print("2)DESC:" + String(tiempo_descarga) + "ms");
  lcd.setCursor(11, 1);
  lcd.print("3)D3:" + String(d3));
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
        delay1();
        goto ini;
      case '2':
        delay2();
        goto ini;
      case '3':
        delay3();
        goto ini;
      case 'A':
        opc2();
        return;
      case 'B':
        opc4();
        return;
      default:
        goto ini;       
    }    
  }  
}
void delay1(){
  d1 = input_int("DELAY 1 us (" + String(d1) + ")", 0, 10000, "ms"); 
  if (d1 != -1)
    EEPROM.put( 50, d1 );  
  else
    EEPROM.get( 50, d1 );
}
void delay2(){
  tiempo_descarga = input_int("T.DESC ms (" + String(tiempo_descarga) + ")", 100, 30000, "ms"); 
  if (tiempo_descarga != -1) {
    d2 = tiempo_descarga;
    EEPROM.put( 60, tiempo_descarga );  
  } else {
    EEPROM.get( 60, tiempo_descarga );
    if (tiempo_descarga <= 0 || tiempo_descarga > 30000) {
      tiempo_descarga = 2000;
    }
    d2 = tiempo_descarga;
  }
}
void delay3(){
  d3 = input_int("DELAY 3 us (" + String(d3) + ")", 0, 10000, "ms"); 
  if (d3 != -1)
    EEPROM.put( 70, d3 );  
  else
    EEPROM.get( 70, d3 );
}