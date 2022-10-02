void valor_incorrecto(double val_min, double val_max){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("VALOR INCORRECTO:"); 
  lcd.setCursor(3, 1);
  lcd.print("VAL. MIN=");
  lcd.print(val_min);
  lcd.setCursor(3, 2);
  lcd.print("VAL. MAX=");
  lcd.print(val_max);  
  delay(4000);
}
void valor_ingresado(String val, String unidad){
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("VALOR INGRESADO:");       
  lcd.setCursor(10-(val.length()/2), 2);         
  lcd.print(val);
  lcd.print(" ");
  lcd.print(unidad);
  delay(2000);
}
void msgbox_acceso(boolean valor){
  if(valor){
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("ACCESO CONCEDIDO");       
    delay(2000);
  }
  else{
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("ACCESO  DENEGADO");       
    delay(2000);
  }  
}
void parada_emergencia(){
  if (pe()==0){
    mensaje_pe();
  }
}
void mensaje_pe(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("PARADA DE EMERGENCIA");
  lcd.setCursor(6, 2);
  lcd.print("ACTIVADA");
  salida_off(arrastre);
  salida_off(mordazas);
  while(pe()==0){     
    switch(tec()){
      case '*':       
        scr_inicio();
        break; 
    } 
    delay(100);      
  }
  scr_inicio();
}
void mensaje(String mensaje){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(mensaje);
  lcd.setCursor(6, 2);
  delay(2000);
  }
  
