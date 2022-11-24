void calibracion_tara(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(2, 3);
  lcd.print("Realizando Tara");
  cell.set_scale(set_scale);
  cell.tare(20);
  lcd.setCursor(0, 2);
  for (int h = 0; h < 20; h++){      
    lcd.write((byte)0);
    delay(80);
  }
}
void calibracion_avanzada(){ 
  peso_ref = input_int("INGRESE PESO", 1, 1000, "gr");
  cell.set_scale();
  if (peso_ref == 0){
    calibracion_incompleta();
    cargar_valores();
    return;
  }
  cell.tare(20);
  if (input_int("COLOQUE LA PESA", 0, 0, "") == -1){
    calibracion_incompleta();
    cargar_valores();
    return;
  }
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("CALIBRANDO...") ;
  set_scale = cell.get_value(40);
  set_scale = set_scale / peso_ref;
  cell.set_scale(set_scale);
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
  EEPROM.put( 10, set_scale );
  cell.tare(20);
  delay(1500);
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("CALIBRACION");
  lcd.setCursor(6, 2);
  lcd.print("EXITOSA");
  delay(2000);
}
void calibracion_incompleta(){
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("CALIBRACION");
  lcd.setCursor(5, 2);
  lcd.print("INCOMPLETA");
  delay(1500);
}
