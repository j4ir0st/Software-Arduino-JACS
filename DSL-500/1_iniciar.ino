void iniciar(){ 
  if (var_modo == 1){
    /* Inicia en modo pulsador */
    iniciar_pul();
    /* ----------------------- */
  }
  else{
    /* Inicia en modo automático */
    iniciar_aut();
    /* ------------------------- */
  }
  EEPROM.update( 160, contador );
  digitalWrite(son,LOW);
  var_cont = contador; 
}
void iniciar_pul(){
  /* Mueve el servo a la posición inicial (6_pos_ini) */
  pos_ini();
  /* ------------------------------------------------ */
  ini:
    /* Imprime pantalla de inicio mientras funciona la máquina en modo pulsador */
    lcd.clear();  
    lcd.setCursor(3, 0);
    lcd.print("JACS MAQUINAS");
    lcd.setCursor(3, 1);
    lcd.print("MODO PULSADOR");
    lcd.setCursor(0, 2);
    lcd.print("DOSIS: " + String(var_dosis) + " cm3");  
    lcd.setCursor(0, 3);
    lcd.print("*)Detener  D)Set vel");
    /* ------------------------------------------------------------------------- */ 
    while(regresar() == false){
      switch(TECLA){
        case 'D':          
          set_velocidad();
          goto ini;
        case '*': 
          regresar();        
          return;
        default:
          goto ini;
    }
    /* Revisa si la parada de emergencia está activa (msgbox)      
    mensaje_pe();  //imprime mensaje de parada de emergencia
    /* ------------------------------------------------------ */     
    /* Dosifica si se activa el pulsador (2_set_dosis) */
    if (digitalRead(PULSADOR) == 1)
      dosificar();          
    /* ----------------------------------------------- */
  } 
}
void iniciar_aut(){ 
  /* Mueve el servo a la posición inicial (6_pos_ini) */
  pos_ini();
  /* ------------------------------------------------ */
ini:
  /* Imprime pantalla de inicio mientras no funciona la máquina en modo automático */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(2, 1);
  lcd.print("MODO AUTO(Off)(" + String(var_delay_aut) + ")  ");
  lcd.setCursor(0, 2);
  lcd.print("DOSIS: " + String(var_dosis) + " cm3");
  lcd.setCursor(0, 3);
  lcd.print("*)Detener  D)Set vel");
  /* ----------------------------------------------------------------------------- */   
  if (pulsador()){
    for(float x = var_delay_aut; x >= 0; x = x - 0.05){
      /* Imprime pantalla de inicio mientras funciona la máquina en modo automático */
      lcd.setCursor(2, 1);
      lcd.print("MODO AUTO(On)(" + String(int(x)) + ")  ");
      /* -------------------------------------------------------------------------- */
      TECLA = teclado.getKey(); 
      if (digitalRead(PULSADOR) == 1 || TECLA == '*'){
        TECLA = '*';
        regresar();
        goto ini;  
      }     
      mensaje_pe();
      if (x <= 0.05){
        x = var_delay_aut;
        dosificar();
      }
      else{
        delay(50);
      }
    }           
  }
  if (TECLA == 'D')
    goto ini;
}
bool pulsador(){
  for(int i = 0; i < 1; i){
    if (digitalRead(PULSADOR) == 1){
      delay(200);
      return true;
    }
    TECLA = teclado.getKey();
    switch(TECLA){
      case 'D':          
        set_velocidad_d();
        TECLA = 'D';
        return false;
      case '*':
        regresar();
        TECLA = 'D';
        return false;
    }
  }
}
