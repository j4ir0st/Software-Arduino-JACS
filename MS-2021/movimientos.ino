void arrastrar(){
  parada_emergencia();
  salida_on(arrastre);
  delay(ar_arrastre);
  for(int i=0;i<1;i){
    parada_emergencia();          
    switch(tec()){            
      case '*': 
        salida_off(arrastre); 
        EEPROM.put(65,contador);        
        detener();
        scr_inicio();
        break; 
    } 
    if (s_taca==1){
      if (ta()==1){
        salida_off(arrastre);   
        return; 
      }
    }
    else{      
      salida_off(arrastre);   
      return;
    }
    //delay(200);         
  }
}
void dosificar(){
  parada_emergencia();
  switch(m_dos){
    case 0:
      salida_off(dos_baja);
      salida_on(actuador);
      delay(ar_actd);
      salida_on(dos_sube);
      delay(ar_doss);
      for(int i=0;i<1;i){
        parada_emergencia();
        switch(tec()){
          case '*':
            EEPROM.put(65,contador);
            detener();
            scr_inicio();
            break;
          }
        if (fd()==1){
          salida_off(dos_sube);
          salida_off(actuador);
          delay(ar_actc);        
          salida_on(dos_baja);
          return;
        }     
      }
      break;
    case 1:
      parada_emergencia();
      if(ar_prearrastre>0){
        salida_on(arrastre);
        delay(ar_prearrastre);
        salida_off(arrastre);
      }
      salida_off(dos_baja);
      salida_on(actuador);
      delay(ar_actd);
      salida_on(dos_sube);
      delay(ar_doss);
      for(int i=0;i<1;i){
        parada_emergencia();
        switch(tec()){
          case '*':
            EEPROM.put(65,contador);
            detener();
            scr_inicio();
            break;
          }
        if (fd()==1){
          salida_off(dos_sube);
          salida_off(actuador);
          delay(ar_actc);        
          salida_on(dos_baja);
          delay(ar_dosb);
          return;
        } 
      }     
      break;
  }
}
void mor_cierra(){
  parada_emergencia();
  salida_on(mordazas);
  delay(ar_morc);
  for(int i=0;i<1;i){
    parada_emergencia();
    switch(tec()){
    case '*':
      EEPROM.put(65,contador);
      detener();
      scr_inicio();
      break;
    }
    if(fc_mor==1){
      if(mo()==1){
        return;
      }
    }
    else{
      return;
    }
  }  
}
void mor_abre(){
  parada_emergencia();
  switch(tec()){
    case '*':
      EEPROM.put(65,contador);
      detener();
      scr_inicio();
      break;
  }
  salida_off(mordazas);
  delay(ar_mora);
}

void envasar(){
  parada_emergencia();
  lcd.clear();
  lcd.print("     ENVASANDO");
  lcd.setCursor(0, 1);
  lcd.print("DOSIFICADOR("+ String(sd()) +")");  
  lcd.setCursor(0, 2);
  lcd.print("CONTADOR   ("+ String(contador) +")");  
  lcd.setCursor(0, 3);
  lcd.print("*)Inicio");
  //pinMode(29,OUTPUT);   
  //pinMode(31,INPUT); 
  //digitalWrite(29,HIGH); 
  salida_on(dos_baja);
  delay(ar_dosb);
  salida_off(dos_baja);
  
  for(int i=0;i<1;i){
    parada_emergencia();
    env_fin=millis();
    env_tiempo=(60/((env_fin-env_inicio)/1000));
    env_inicio=millis();
    delay(200);      
    switch(tec()){
      case '*':
        EEPROM.put(65,contador);
        detener();
        scr_inicio();
        break;
    }
    switch(sec){
      case 0:
        mor_cierra();
        delay(t_sellado);
        mor_abre();
        if(sd()==1){
          dosificar();
        }
        arrastrar();
        contador++;
        break;
      case 1:
        mor_cierra();
        if(sd()==1){
          dosificar();
        }
        else{
          delay(t_sellado);
        }
        mor_abre();
        arrastrar();
        contador++;
        break;
    }           
    //delay(200);
    lcd.setCursor(0, 1);
    if(sd()==0){
      lcd.print("DOSIFICADOR(Off)");  
    }
    else{
      lcd.print("DOSIFICADOR(On)");
    }    
    lcd.setCursor(0, 2);
      lcd.print("PROD X MIN("+ String(env_tiempo) +")"); 
    lcd.setCursor(10, 3);
    lcd.print("N:"+ String(contador) );      
        
  }
}

void arrastrar_taca(){
  parada_emergencia();
  salida_on(arrastre);
  delay(ar_arrastre);
  for(int i=0;i<1;i){ 
    parada_emergencia();         
    switch(tec()){            
      case '*': 
        salida_off(arrastre); 
        return;
        break; 
    } 
    if (s_taca==1){
      if (ta()==1){
        salida_off(arrastre);   
        return; 
      }
    }
    else{      
      salida_off(arrastre);   
      return;
    }      
  }
}
void arrastrar_ar(){
  parada_emergencia();
  salida_on(arrastre);
  delay(ar_arrastre);
  salida_off(arrastre);
}
void arrastrar_par(){
  parada_emergencia();
  salida_on(arrastre);
  delay(ar_prearrastre);
  salida_off(arrastre);
}
void dosificar1(){
  parada_emergencia();
  switch(m_dos){
    case 0:
      salida_off(dos_baja);
      salida_on(actuador);
      delay(ar_actd);
      salida_on(dos_sube);
      delay(ar_doss);
      for(int i=0;i<1;i){
        parada_emergencia();
        switch(tec()){
          case '*':
            return;
            break;
          }
        if (fd()==1){
          salida_off(dos_sube);
          salida_off(actuador);
          delay(ar_actc);        
          salida_on(dos_baja);
          return;
        }     
      }
      break;
    case 1:
      parada_emergencia();
      salida_off(dos_baja);
      salida_on(actuador);
      delay(ar_actd);
      salida_on(dos_sube);
      delay(ar_doss);
      for(int i=0;i<1;i){
        parada_emergencia();
        switch(tec()){
          case '*':
            return;
            break;
          }
        if (fd()==1){
          salida_off(dos_sube);
          salida_off(actuador);
          delay(ar_actc);        
          salida_on(dos_baja);
          delay(ar_dosb);
          return;
        } 
      }     
      break;
  }
}

void detener(){
  lcd.clear();
  lcd.print("   JACS MAQUINAS");
  lcd.setCursor(3, 3);
  lcd.print("Finalizando...");  
  salida_off(mordazas);
  salida_off(actuador);
  salida_off(dos_sube);
  salida_off(dos_baja);
  salida_off(arrastre);
  delay(2000);      
}

void jog_arrastre(){
  while(digitalRead(AR)==1){
    
    digitalWrite(arrastre,HIGH);
  }
  digitalWrite(arrastre,LOW);
}
