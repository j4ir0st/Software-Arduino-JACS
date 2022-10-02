void opc_1(){
ini:
  /* Imprime pantalla de menú dosis */
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("DOSIS       A");
  lcd.setCursor(0, 1);
  lcd.print("1)DOSIS(" + String(var_dosis) + "ml)");  
  lcd.setCursor(0, 2);
  lcd.print("2)REPETIR (" + String(var_repetir) + ")");
  lcd.setCursor(14, 1);
  lcd.print("3)ERR");
  lcd.setCursor(14, 2);
  lcd.print("4)DMx");
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* ------------------------------ */
  switch(tec()){
    case '1':
      set_dosis();
      goto ini;
    case '2':
      set_repetir();
      goto ini;
    case '3':
      set_error();
      goto ini;
    case '4':
      set_dosis_max(); 
      goto ini;
    case 'A':
      opc_9();  
      return;
    case 'B':  
      opc_2();
      return;
    case '*':  
      return;
    default:
      goto ini;
  }
}
void set_repetir(){
  var_repetir = input_int("INGRESE REPETICIONES", 0, 20, "", String(var_repetir));
  if (var_repetir >= 0){
    EEPROM.update( 120, var_repetir );
  } 
  else{
    EEPROM.get( 120, var_repetir );  
  }
}
void set_error(){
  var_error = input_dbl("INGRESE ERROR", 0, 20, "cm3");
  if (var_error == -1){
    EEPROM.get( 90, var_error );
    return;
  } 
  EEPROM.update( 50, var_error );   
  diametro_embolo1 = diametro_embolo; 
  var_longitud = (var_dosis + var_error) / ((pow(((diametro_embolo1 / 2) / 10), 2)) * (pi));
  var_longitud = var_longitud * 10;
  var_paso1 = var_paso;
  pulsos_dosis = (pulsos_rev * var_longitud) / (var_paso1);
  EEPROM.update( 80, pulsos_dosis );
}
