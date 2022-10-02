void pos_ini(){
  /* --Mueve el servo a la posición inicial-- */
  pos0();
  digitalWrite(son, HIGH);
  delay(500);
  lcd.clear();
  lcd.print("   JACS MAQUINAS");
  lcd.setCursor(0, 3);
  lcd.print("Moviendo a POS 1...");
  mensaje_pe();
  cont = pulsos_dosis;
  while(cont > 0){
    cont--;
    digitalWrite(pulso, HIGH);
    delayMicroseconds(var_delay);
    digitalWrite(pulso, LOW);
    delayMicroseconds(var_delay); 
    mensaje_pe();
  }
  delay(500);
  digitalWrite(son, LOW);
  delay(500);
}

void pos0(){
  /* --Mueve el servo a la posición 0-- */
  mensaje_pe();
  lcd.clear();
  lcd.print("   JACS MAQUINAS");
  lcd.setCursor(0, 3);
  lcd.print("Moviendo a POS 0...");
  digitalWrite(sentido, HIGH);
  digitalWrite(son, HIGH);
  delay(1000); 
  while(digitalRead(POS0) == 0){
    digitalWrite(pulso, HIGH);
    delayMicroseconds(1000);
    digitalWrite(pulso, LOW);
    delayMicroseconds(1000);
    mensaje_pe();
  }
  delay(1000);
  digitalWrite(sentido,LOW);
  delay(1000);
  while(digitalRead(POS0) == 1){
    digitalWrite(pulso, HIGH);
    delayMicroseconds(2000);
    digitalWrite(pulso, LOW);
    delayMicroseconds(2000);
    mensaje_pe();
  }
  delay(500);
  digitalWrite(son, LOW);
  delay(500);
}