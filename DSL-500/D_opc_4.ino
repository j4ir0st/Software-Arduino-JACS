void opc_4(){
ini:
  /* Imprime pantalla de menú dosificador */
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("DOSIFICADOR    A");
  lcd.setCursor(0, 1);
  lcd.print("1)D.EMBOLO (" + String(diametro_embolo) + "mm)");  
  lcd.setCursor(0, 2);
  lcd.print("2)PAS.EJE (" + String(var_paso) + "mm)");
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* ---------------------------------- */
  switch(tec()){
    case '1':
      set_embolo();        
      goto ini;
    case '2':  
      set_paso();        
      goto ini;
    case 'A':
      opc_3();
      return;  
    case 'B':
      opc_5();
      return;
    case '*':  
      return;
    default:
      goto ini;
  }   
}
void set_embolo(){
  diametro_embolo = input_int("INGRESE D. DE EMBOLO", 26, 100, "mm");
  if (diametro_embolo > 0){
    EEPROM.update( 10, diametro_embolo );
  } 
  else{
    EEPROM.get( 10, diametro_embolo );  
  }
}
void set_paso(){
  var_paso = input_dbl("INGRESE PASO DE EJE", 1, 20, "mm");
  if (var_paso > 0){
    EEPROM.update( 20, var_paso );
  } 
  else{
    EEPROM.get( 20, var_paso );  
  }
}
