/* MENÚ DESCARGA */
void opc3(){
ini:
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("DESCARGA");
  lcd.setCursor(0, 1);
  lcd.print("1)D1:" + String(d1));
  lcd.setCursor(0, 2);
  lcd.print("2)D2:" + String(d2));
  lcd.setCursor(11, 1);
  lcd.print("3)D3:" + String(d3));
  // lcd.setCursor(11, 2);
  // lcd.print("4)Pin:" + String(pulsador));
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
      // case '4':
      //   set_pin();
      //   goto ini;
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
  d2 = input_int("DELAY 2 us (" + String(d2) + ")", 0, 10000, "ms"); 
  if (d2 != -1)
    EEPROM.put( 60, d2 );  
  else
    EEPROM.get( 60, d2 );
}
void delay3(){
  d3 = input_int("DELAY 3 us (" + String(d3) + ")", 0, 10000, "ms"); 
  if (d3 != -1)
    EEPROM.put( 70, d3 );  
  else
    EEPROM.get( 70, d3 );
}
// void set_pin(){
//   pulsador = input_int("PULSADOR (" + String(pulsador) + ")", 0, 100, ""); 
//   if (d1 != -1)
//     EEPROM.put( 130, pulsador );  
//   else
//     EEPROM.get( 130, pulsador );
// }