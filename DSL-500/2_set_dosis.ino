void set_dosis(){
  var_dosis = input_int("INGRESE DOSIS", 1, var_dosis_max, "ml");  
  if (var_dosis > 0){
    EEPROM.update( 0, var_dosis ); 
  }
  else{
    EEPROM.get( 0, var_dosis ); 
  }
  /* Si la dosis es mayor a 500 repite dosis */
  while (var_dosis > 500){
    var_dosis = var_dosis / 2;
    var_repetir = var_repetir * 2;
    EEPROM.update( 120, var_repetir ); 
  }
  /* --------------------------------------- */
  /* Calculamos los pulsos */
  diametro_embolo1 = diametro_embolo;
  var_longitud = (var_dosis + var_error) / ((pow(((diametro_embolo1 / 2) / 10), 2)) * (pi));
  var_longitud = var_longitud * 10;
  var_paso1 = var_paso;
  pulsos_dosis = (pulsos_rev * var_longitud) / (var_paso1);
  /* --------------------- */
  EEPROM.update( 80, pulsos_dosis );
  return;
}
void set_dosis_max(){
  var_dosis_max = input_int("INGRESE DOSIS MAXIMA", 1, 2000, "ml");
  if (var_dosis_max > 0){
    EEPROM.update( 100, var_dosis_max );
  } 
  else{
    EEPROM.get( 100, var_dosis_max );  
  }
}
void dosificar(){ 
  for (int i = 0; i <= var_repetir; i++){
    mensaje_pe();  
    cont = pulsos_dosis;
    digitalWrite(son,HIGH);
    digitalWrite(sentido,HIGH);
    delay (300);
    while(cont > 0){
      cont--;
      digitalWrite(pulso, HIGH);
      delayMicroseconds(var_delay);
      digitalWrite(pulso, LOW);
      delayMicroseconds(var_delay); 
      mensaje_pe();   
    }
    digitalWrite(sentido, LOW);
    delay(300);
    cont = pulsos_dosis;
    while(cont > 0){
      cont--;
      digitalWrite(pulso, HIGH);
      delayMicroseconds(var_delay_c);
      digitalWrite(pulso, LOW);
      delayMicroseconds(var_delay_c); 
      mensaje_pe();
    }
    delay(300);
    contador++;
  }
}
