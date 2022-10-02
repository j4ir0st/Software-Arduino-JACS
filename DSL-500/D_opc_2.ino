void opc_2(){
ini:
  /* Imprime pantalla de menú velocidad */
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("VELOCIDAD     A");
  lcd.setCursor(0, 1);
  lcd.print("1)CARG(" + String(var_velocidad_c) + ")");  
  lcd.setCursor(0, 2);
  lcd.print("2)DESC(" + String(var_velocidad_d) + ")");
  lcd.setCursor(14, 1);
  lcd.print("3)VMx");
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* ---------------------------------- */
  switch(tec()){
    case '1':
      set_velocidad_c();        
      goto ini;
    case '2':  
      set_velocidad_d();        
      goto ini;
    case '3':  
      set_velocidad_max();        
      goto ini;
    case 'A':
      opc_1();
      return;  
    case 'B':
      opc_3();
      return;
    case '*':  
      return;
    default:
      goto ini;      
  }
}
void set_velocidad_max(){
  var_velocidad_max = input_int("INGRESE VELOCIDAD Mx", 1, 3000, "rpm");
  if (var_velocidad_max > 0){
    EEPROM.update( 150, var_velocidad_max );
  } 
  else{
    EEPROM.get( 150, var_velocidad_max );  
  }
}
