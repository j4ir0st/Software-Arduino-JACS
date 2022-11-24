/* MENÚ SALIDAS */
void opc7(){
ini:
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("SALIDAS");
  lcd.setCursor(0, 1);
  lcd.print("1)VG:");
  lcd.setCursor(0, 2);
  lcd.print("2)VF:");
  lcd.setCursor(8, 1);
  lcd.print("3)MA:");
  lcd.setCursor(8, 2);
  lcd.print("4)MC:");
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
    lcd.setCursor(6, 1);
    lcd.print(String(digitalRead(gruesa)));
    lcd.setCursor(6, 2);
    lcd.print(String(digitalRead(fina)));
    lcd.setCursor(14, 1);
    lcd.print(String(digitalRead(m_abre)));
    lcd.setCursor(14, 2);
    lcd.print(String(digitalRead(m_cierra)));
    TECLA = teclado.getKey();
    if (TECLA){
      switch(TECLA){
        case '1':
          activar(gruesa);
          goto ini;
        case '2':
          activar(gruesa);
          activar(fina);  
          goto ini;
        case '3':
          activar(m_abre);
          goto ini;
        case '4':
          activar(m_cierra);
          goto ini;      
        case 'A':
          opc6();
          return;
        case 'B':
          opc8();
          return;
        default:
          goto ini;
      }    
    }
    delay(200);
  }
  digitalWrite(gruesa, LOW);
  digitalWrite(fina, LOW);
  digitalWrite(m_abre, LOW);
  digitalWrite(m_cierra, LOW);
}
void activar(int pin){
  pinMode(pin,OUTPUT); 
  digitalWrite(pin,!digitalRead(pin));
  lcd.print(digitalRead(pin));
}