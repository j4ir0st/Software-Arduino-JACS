void mensaje_pe(){
  if (digitalRead(PE)==0){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PARADA DE EMERGENCIA");
    lcd.setCursor(6, 2);
    lcd.print("ACTIVADA");
    while(digitalRead(PE)==0){
    }
    pos0();
    iniciar();
  }  
  if (digitalRead(AUX_IN1)==1){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("   ERROR DE SERVO");
    while(digitalRead(AUX_IN1)==1){
    }
    pos0();
    iniciar();
  }
} 
void valor_incorrecto(double val_min, double val_max){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("VALOR INCORRECTO: "); 
  lcd.setCursor(2, 1);
  lcd.print("VAL. MIN = ");
  lcd.print(val_min);
  lcd.setCursor(2, 2);
  lcd.print("VAL. MAX = ");
  lcd.print(val_max);  
  delay(2500);
}
void valor_ingresado(String val, String unidad){
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("VALOR INGRESADO: ");       
  lcd.setCursor(10 - (val.length() / 2), 2);         
  lcd.print(val);
  lcd.print(" ");
  lcd.print(unidad);
  delay(2000);
}