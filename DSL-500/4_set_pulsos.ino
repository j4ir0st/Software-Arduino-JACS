void set_pulsos(){
  pulsos_dosis = input_int("INGRESE PULSOS", 1, 30000, "pul");  
  if (pulsos_dosis > 0){
    EEPROM.update( 80, pulsos_dosis ); 
  }
  else{
    EEPROM.get( 80, pulsos_dosis ); 
  }
}
