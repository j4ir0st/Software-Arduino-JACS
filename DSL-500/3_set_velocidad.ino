void set_velocidad(){
ini:
  /* Imprime pantalla de set de velocidad */
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("1)CARGA(" + String(var_velocidad_c) + "rpm)");
  lcd.setCursor(0, 2);
  lcd.print("2)DESCARGA(" + String(var_velocidad_d) + "rpm)");
  /* ------------------------------------ */     
  switch(tec()){
    case '1': 
      set_velocidad_c();
      goto ini;
    case '2':
      set_velocidad_d();
      goto ini;
    case '*':
      return;
    default:
      goto ini;                       
  }
}
void set_velocidad_c(){
  /* --Define la velocidad de carga-- */
  var_velocidad_c = input_int("INGRESE VELOCIDAD", 10, var_velocidad_max, "rpm", String(var_velocidad_c));
  if (var_velocidad_c > 9){
    /* Calcula la velocidad de carga */
    var_delay_c = var_velocidad_c / 60;
    var_delay_c = var_delay_c * 2000;
    var_delay_c = 1 / var_delay_c;
    var_delay_c = var_delay_c * 1000000;
    /* ----------------------------- */
    EEPROM.update( 140, var_delay_c ); 
    EEPROM.update( 130, var_velocidad_c ); 
  }
  else{
    EEPROM.get( 130,var_velocidad_c ); 
  }
}
void set_velocidad_d(){
  /* --Define la velocidad de dosificado-- */
  var_velocidad_d = input_int("INGRESE VELOCIDAD", 10, var_velocidad_max, "rpm", String(var_velocidad_d));
  if (var_velocidad_d > 0){
    /* Calcula la velocidad de dosificado */
    var_velocidad = var_velocidad_d;
    var_delay = var_velocidad / 60;
    var_delay = var_delay * 2000;
    var_delay = 1 / var_delay;
    var_delay = var_delay * 1000000;
    /* ---------------------------------- */
    EEPROM.update( 70, var_delay ); 
    EEPROM.update( 60, var_velocidad_d ); 
  }
  else{
    EEPROM.get( 60,var_velocidad_d ); 
  }
}
