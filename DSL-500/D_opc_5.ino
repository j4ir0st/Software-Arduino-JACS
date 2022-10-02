void opc_5(){
ini:
  /* Imprime pantalla de menú servo */
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("SERVO       A");
  lcd.setCursor(0, 1);
  lcd.print("1)PUL.REV(" + String(pulsos_rev) + " pul)");  
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* ------------------------------ */
  switch(tec()){
    case '1':
      set_pulsos_rev();        
      goto ini;
    case 'A':
      opc_4();
      return;  
    case 'B':
      opc_6();
      return;
    case '*':  
      return;
    default:
      goto ini;      
  }
}
void set_pulsos_rev(){
  pulsos_rev = input_int("INGRESE PULSOS X REV", 1, 30000, "pul");
  if (pulsos_rev > 0){
    EEPROM.update( 30, pulsos_rev );
  } 
  else{
    EEPROM.get( 30,pulsos_rev );  
  }
}
