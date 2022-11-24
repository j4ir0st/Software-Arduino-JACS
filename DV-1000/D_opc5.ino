/* MENÚ AUTO CORRECTOR */
void opc5(){
ini:
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("AUTO CORRECTOR");
  lcd.setCursor(0, 1);
  lcd.print("1)");
  if (ac_modo == 0){
    lcd.setCursor(2, 1);
    lcd.print("OFF");
  }    
  if (ac_modo == 1){
    lcd.setCursor(2, 1);
    lcd.print("ON  ");
    lcd.setCursor(0, 2);
    lcd.print("2)T1:" + String(t_ac1));
    lcd.setCursor(10, 1);
    lcd.print("3)T2:" + String(t_ac2));
    lcd.setCursor(10, 2);
    lcd.print("4)T3:" + String(t_ac3));
  }
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
        set_ac_modo();
        goto ini;
      case '2':
        if (ac_modo == 1)
          t1();
        goto ini;
      case '3':
        if (ac_modo == 1)
          t2();
        goto ini;
      case '4':
        if (ac_modo == 1)
          t3();
        goto ini;
      case 'A':
        opc4();
        return;
      case 'B':
        opc6();
        return;
      default:
        goto ini;       
    }    
  }  
}
void set_ac_modo(){
  if (ac_modo == 1){
    ac_modo = 0;
    EEPROM.put( 180, ac_modo );
  } 
  else{
    ac_modo = 1;
    EEPROM.put( 180, ac_modo );  
  }
}
void t1(){
    t_ac1 = input_int("TIEMPO 1 (" + String(t_ac1) + ")", 0, 10000, "ms"); 
  if (t_ac1 != -1)
    EEPROM.put( 150, t_ac1 );  
  else
    EEPROM.get( 150, t_ac1 );
}
void t2(){
    t_ac2 = input_int("TIEMPO 2 (" + String(t_ac2) + ")", 0, 10000, "ms"); 
  if (t_ac2 != -1)
    EEPROM.put( 160, t_ac2 );  
  else
    EEPROM.get( 160, t_ac2 );
}
void t3(){
    t_ac3 = input_int("TIEMPO 3 (" + String(t_ac3) + ")", 0, 10000, "ms"); 
  if (t_ac3 != -1)
    EEPROM.put( 170, t_ac3 );  
  else
    EEPROM.get( 170, t_ac3 );
}