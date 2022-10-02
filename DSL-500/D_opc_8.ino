void opc_8(){
ini:
  /* Imprime pantalla de menú contador */
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("CONTADOR     A");
  lcd.setCursor(0, 1);
  lcd.print("1)CONTADOR  : " + String(var_cont));  
  lcd.setCursor(0, 2);
  lcd.print("2)CONTADOR T: " + String(contador));
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* -------------------------------------------- */
  switch(tec()){
    case 'C':
      get_contador();
      goto ini;
    case '2':    
      goto ini;
    case 'A':
      opc_7();
      return;  
    case 'B':
      opc_9();
      return;
    case '*':
      return;
    default:
      goto ini;      
  }  
}
void get_contador(){
  int var = 0;
  var = input_int("CONTADOR", 0, 30000, "", String(contador));
  if (var >= 0){
    EEPROM.update( 100, var );
    contador = var;    
  }
}
