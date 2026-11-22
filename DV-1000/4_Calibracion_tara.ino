/* ========================================================================== */
/* RUTINAS DE CALIBRACIÓN Y TARA DE LA CELDA DE CARGA                         */
/* ========================================================================== */

/* 
 * calibracion_tara:
 * Realiza la tara (puesta a cero) de la balanza aplicando el factor de escala actual.
 */
void calibracion_tara(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(2, 3);
  lcd.print("Realizando Tara");
  celda.set_scale(escala_calibracion);
  celda.tare(20);
  lcd.setCursor(0, 2);
  for (int h = 0; h < 20; h++){      
    lcd.write((byte)0);
    delay(80);
  }
}

/* 
 * calibracion_avanzada:
 * Calibra la celda de carga paso a paso con una masa patrón conocida.
 */
void calibracion_avanzada(){ 
  peso_ref = input_int("INGRESE PESO", 1, 1000, "gr");
  celda.set_scale();
  if (peso_ref == 0){
    calibracion_incompleta();
    cargar_valores();
    return;
  }
  celda.tare(20);
  if (input_int("COLOQUE LA PESA", 0, 0, "") == -1){
    calibracion_incompleta();
    cargar_valores();
    return;
  }
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("CALIBRANDO...") ;
  escala_calibracion = celda.get_value(40);
  escala_calibracion = escala_calibracion / peso_ref;
  celda.set_scale(escala_calibracion);
  lcd.setCursor(0, 2);
  for (int h = 0; h < 20; h++){      
    lcd.write((byte)0);
    delay(80);
  }
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("RETIRE LA PESA");
  delay(1500);
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("GUARDANDO DATOS");
  lcd.setCursor(0, 2);
  for (int h = 0; h < 20; h++){      
    lcd.write((byte)0);
    delay(80);
  } 
  EEPROM.put( 0, peso_ref );
  EEPROM.put( 10, escala_calibracion );
  celda.tare(20);
  delay(1500);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("CALIBRACION");
  lcd.setCursor(6, 2);
  lcd.print("EXITOSA");
  delay(2000);
}

/* 
 * calibracion_incompleta:
 * Muestra mensaje de advertencia si el proceso de calibración es cancelado.
 */
void calibracion_incompleta(){
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("CALIBRACION");
  lcd.setCursor(5, 2);
  lcd.print("INCOMPLETA");
  delay(1500);
}
