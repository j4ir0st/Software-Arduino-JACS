/* MENÚ CONTADOR */
void opc8(){
ini:
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("CONTADOR");
  lcd.setCursor(0, 1);
  lcd.print("1)CONT   ACT:" + String(var_cont));  
  lcd.setCursor(0, 2);
  lcd.print("2)CONT TOTAL:" + String(contador));
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
      case 'C':
        if (input_clave("PASSWORD", 0, 900000, "-") == e)
          get_contador();
        goto ini;
      case 'A':
        opc7();
        return;
      case 'B':
        opc9();
        return;
      default:
        goto ini;       
    }    
  }  
}
void get_contador(){
  int var = 0;
  var = input_int("CONTADOR (" + String(contador) + ")", 0, 30000, "");
  if (var >= 0){
    EEPROM.put( 100, var );
    contador = var;    
  }
}