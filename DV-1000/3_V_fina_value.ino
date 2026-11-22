/* ========================================================================== */
/* CONFIGURACIÓN DEL RANGO DE VIBRACIÓN FINA                                  */
/* ========================================================================== */

/* 
 * v_fina_value:
 * Permite ajustar manualmente desde el teclado los gramos de corte previo
 * para la dosificación fina de precisión.
 */
void v_fina_value(){
  v_fina = input_int("VIB. FINA (" + String(v_fina) + ")", 0, 1000, "gr");
  if (v_fina != -1){
    EEPROM.put( 80, v_fina ); 
  } 
  else{
    EEPROM.get( 80, v_fina );  
  }
}
