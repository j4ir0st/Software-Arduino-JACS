void opc_6(){
ini:
  /* Imprime pantalla de menú control de entradas */
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("CONTROL ENTRADAS  A");
  lcd.setCursor(0, 1);
  lcd.print("1)EMERGENCIA: " + digitalRead(PE));  
  lcd.setCursor(0, 2);
  lcd.print("2)PULSADOR  : " + digitalRead(PULSADOR));
  lcd.setCursor(0, 3);
  lcd.print("3)POSICION 0: " + digitalRead(POS0));
  lcd.setCursor(19, 3);
  lcd.print("B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* -------------------------------------------- */
  switch(tec()){
    case 'A':
      opc_5();
      return;  
    case 'B':
      opc_7();
      return;
    case '*':  
      return;
    default:
      goto ini;     
  }
}
