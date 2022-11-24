void set_peso(){
  s_peso = input_int("INGRESE EL PESO", peso_min, peso_max, "gr");
  if (s_peso != -1){
    EEPROM.put( 20, s_peso ); 
  }
  else{
    EEPROM.get( 20, s_peso ); 
  }
}
int get_peso(){ 
  peso = cell.get_units();
  return(peso);
}
int print_peso(){
  peso = get_peso();
  lcd.setCursor(7, 1);    
  lcd.print("          ");
  lcd.setCursor(7, 1);    
  lcd.print(String(roundf(peso)) +" gr");
  return(peso);
}