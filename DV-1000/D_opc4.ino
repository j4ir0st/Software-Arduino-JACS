/* MENÚ MODO */
void opc4(){
ini:
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("MODO");
  lcd.setCursor(0, 1);
  lcd.print("1)");
  if (i_modo == 2){
    lcd.setCursor(2, 1);
    lcd.print("MANUAL    ");
  }    
  if (i_modo == 1){
    lcd.setCursor(2, 1);
    lcd.print("AUTOMATICO");
    lcd.setCursor(0, 2);
    lcd.print("2)DELAY (" + String(delay_aut) + " ms)");
  }
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
        set_modo();
        goto ini;
      case '2':
        if (i_modo == 1)
          set_modo_delay();
        goto ini;
      case 'A':
        opc3();
        return;
      case 'B':
        opc5();
        return;
      default:
        goto ini;       
    }    
  }  
}
void set_modo(){
  if (i_modo == 1){
    i_modo = 2;
    EEPROM.put( 30, i_modo );
  } 
  else{
    i_modo = 1;
    EEPROM.put( 30, i_modo );  
  }
}
void set_modo_delay(){
    delay_aut = input_int("DELAY (" + String(delay_aut) + ")", 0, 10000, "ms"); 
  if (delay_aut != -1)
    EEPROM.put( 120, delay_aut );  
  else
    EEPROM.get( 120, delay_aut );
}