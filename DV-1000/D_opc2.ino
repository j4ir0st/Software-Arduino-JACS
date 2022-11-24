/* MENÚ PESO */
void opc2(){
ini:
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("PESO");
  lcd.setCursor(0, 1);
  lcd.print("1)Maximo (" + String(peso_max) + " gr)");
  lcd.setCursor(0, 2);
  lcd.print("2)Minimo (" + String(peso_min) + " gr)");
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
  if (tec()){
    switch(TECLA){
      case '*':  
        return;        
      case '1':
        peso_maximo();
        goto ini;
      case '2':
        peso_minimo();
        goto ini;
      case 'A':
        opc1();
        return;
      case 'B':
        opc3();
        return;
      default:
        goto ini;       
    }    
  }  
}
void peso_maximo(){
  peso_max = input_int("PESO MAX (" + String(peso_max) + ")", 0, 10000, "gr");
  if (peso_max != -1){
    EEPROM.put( 100, peso_max ); 
  } 
  else{
    EEPROM.get( 100, peso_max );  
  }
}
void peso_minimo(){
  peso_min = input_int("PESO MIN (" + String(peso_min) + ")", 0, 10000, "gr");
  if (peso_min != -1){
    EEPROM.put( 110, peso_min ); 
  } 
  else{
    EEPROM.get( 110, peso_min );  
  }
}