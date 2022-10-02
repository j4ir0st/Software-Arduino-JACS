void set_delay(){
  var_delay = input_int("INGRESE DELAY", 10, 5000, "ms");  
  if (var_delay > 0){
    EEPROM.update( 70, var_delay ); 
  }
  else{
    EEPROM.get( 70,var_delay ); 
  }
}
