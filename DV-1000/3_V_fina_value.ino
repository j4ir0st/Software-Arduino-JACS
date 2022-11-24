void v_fina_value(){
  v_fina = input_int("VIB. FINA (" + String(v_fina) + ")", 0, 1000, "gr");
  if (v_fina != -1){
    EEPROM.put( 80, v_fina ); 
  } 
  else{
    EEPROM.get( 80, v_fina );  
  }
}