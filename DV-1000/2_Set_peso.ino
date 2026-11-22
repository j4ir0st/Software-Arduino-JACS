/* ========================================================================== */
/* CONFIGURACIÓN Y LECTURA DEL PESO DESDE LA BALANZA                          */
/* ========================================================================== */

/* 
 * set_peso:
 * Permite ingresar el peso objetivo de forma manual desde el teclado y guardarlo en EEPROM.
 */
void set_peso(){
  s_peso = input_int("INGRESE EL PESO", peso_min, peso_max, "gr");
  if (s_peso != -1){
    EEPROM.put( 20, s_peso ); 
  }
  else{
    EEPROM.get( 20, s_peso ); 
  }
}

/* 
 * get_peso:
 * Obtiene la lectura instantánea de peso desde la celda de carga HX711.
 */
int get_peso(){ 
  peso = celda.get_units();
  return(peso);
}

/* 
 * print_peso:
 * Lee el peso actual de la celda y lo muestra formateado en la pantalla LCD.
 */
int print_peso(){
  peso = get_peso();
  lcd.setCursor(7, 1);    
  lcd.print("          ");
  lcd.setCursor(7, 1);    
  lcd.print(String(roundf(peso)) + " gr");
  return(peso);
}
