void opc_7(){
ini:
  /* Imprime pantalla de menú control de salidas */
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("CONTROL SALIDAS   A");
  lcd.setCursor(0, 1);
  lcd.print("1)SERVO ON  : " + digitalRead(PE));  
  lcd.setCursor(0, 2);
  lcd.print("2)SIGN      : " + digitalRead(PULSADOR));
  lcd.setCursor(0, 3);
  lcd.print("3)PULSE     : " + digitalRead(POS0));
  lcd.setCursor(19, 3);
  lcd.print("B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* -------------------------------------------- */
  switch(tec()){
    case '1':
      activar(son);
      goto ini;
    case '2':
      activar(sentido);     
      goto ini;
    case '3':
      activar(pulso);
      goto ini;
    case 'A':
      opc_6();
      return;  
    case 'B':
      opc_8();
      return;
    case '*':
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW); 
      return;
    default:
      goto ini;      
  } 
}
void activar(int pin){
  pinMode(pin,OUTPUT); 
  digitalWrite(pin,!digitalRead(pin));
}
