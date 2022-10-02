void opc_3(){
ini:
  /* Imprime pantalla de menú modo */
  lcd.clear();
  lcd.setCursor(8, 0);
  lcd.print("MODO       A");
  lcd.setCursor(0, 1);
  lcd.print("1)");
  if (var_modo==1){
    lcd.setCursor(2, 1);
    lcd.print("MANUAL");
  } 
  if (var_modo==2){
    lcd.setCursor(2, 1);
    lcd.print("AUTOM");
  }  
  lcd.setCursor(0, 2);
  lcd.print("2)DELAY AUT(" + String(var_delay_aut) + ")");
  lcd.setCursor(14, 1);
  lcd.print("3)SNS");
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* ---------------------------------- */
  switch(tec()){
    case '1':
      set_modo();        
      goto ini;
    case '2':  
      set_delay_aut();        
      goto ini;
    case '3':       
      goto ini;
    case 'A':
      opc_2();
      return;  
    case 'B':
      opc_4();
      return;
    case '*':  
      return;
    default:
      goto ini;      
  }
}
void set_modo(){
  var_modo = input_int("INGRESE MODO", 1, 2, "", "1=MANUAL 2=AUTOM");
  if (var_modo > 0){
    EEPROM.update( 40, var_modo );
  } 
  else{
    EEPROM.get( 40, var_modo );  
  }
}
void set_delay_aut(){
  var_delay_aut = input_int("INGRESE RETARDO", 1, 50, "seg");
  if (var_delay_aut > 0){
    EEPROM.update( 110, var_delay_aut );
  } 
  else{
    EEPROM.get( 110, var_delay_aut );  
  }
}
