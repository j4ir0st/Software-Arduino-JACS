/* MENÚ ENTRADAS */
void opc6(){
ini:
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("ENTRADAS");
  lcd.setCursor(0, 1);
  lcd.print("A0:" + String(digitalRead(A0)));
  lcd.setCursor(0, 2);
  lcd.print("A1:" + String(digitalRead(A1)));
  lcd.setCursor(6, 1);
  lcd.print("A2:" + String(digitalRead(A2)));
  lcd.setCursor(6, 2);
  lcd.print("A3:" + String(digitalRead(A3)));
  lcd.setCursor(12, 1);
  lcd.print("A4:" + String(digitalRead(A4)));
  lcd.setCursor(12, 2);
  lcd.print("A5:" + String(digitalRead(A5)));
  lcd.setCursor(0, 3);
  lcd.print("*)Inicio");
  lcd.setCursor(19, 0);
  lcd.print("A");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  lcd.setCursor(19, 3);
  lcd.print("B");
  while(TECLA != '*'){
    lcd.setCursor(3, 1);
    lcd.print(String(digitalRead(A0)));
    lcd.setCursor(3, 2);
    lcd.print(String(digitalRead(A1)));
    lcd.setCursor(9, 1);
    lcd.print(String(digitalRead(A2)));
    lcd.setCursor(9, 2);
    lcd.print(String(digitalRead(A3)));
    lcd.setCursor(15, 1);
    lcd.print(String(digitalRead(A4)));
    lcd.setCursor(15, 2);
    lcd.print(String(digitalRead(A5)));
    TECLA = teclado.getKey();
    if (TECLA){
      switch(TECLA){       
        case 'A':
          opc5();
          return;
        case 'B':
          opc7();
          return;
        default:
          goto ini;
      }    
    }
    delay(200);
  }  
}