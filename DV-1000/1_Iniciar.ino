void iniciar(){
  /* limpiamos la celda de carga */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(4, 3);
  lcd.print("Iniciando...");
  delay(500);
  /* --------------------------- */
  listo=false;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 3);
  lcd.print("*)Detener");
  lcd.setCursor(0, 1);
  lcd.print("PESO:");
  peso_vg = s_peso - v_fina;
  peso_vf = s_peso - inercia;
  while(regresar() == false){
    peso = print_peso();
    if(peso <= peso_vg)
      digitalWrite(gruesa, HIGH);
    else if(peso < peso_vf && peso >= peso_vg){
      digitalWrite(fina, HIGH);
    }
    else{
      digitalWrite(gruesa, LOW);
      digitalWrite(fina, LOW);
      if(i_modo == 1){
        auto_corrector();
        delay(delay_aut);
        descargar();
        contador++;
        var_cont++;
      }
      else if(i_modo == 2){
        auto_corrector();
        while(1){
          TECLA = teclado.getKey();
          peso = print_peso();
          if(regresar())
            return;
          /* Presionar el boton parada de emergancia descarga el producto (cambiar a interrupciones)*/
          if(digitalRead(PE) == 0 || digitalRead(pulsador) == 1 || TECLA == '#'){
            descargar();
            contador++;
            var_cont++;
            break;
          }
          /* -------------------------------------------------------------------------------------- */ 
        }
      }
    }           
  }
}
void auto_corrector(){
  if (ac_modo == 1){
    peso = print_peso();
    while(peso < s_peso){
      delay(t_ac1);
      digitalWrite(gruesa, HIGH);
      digitalWrite(fina, HIGH);
      delay(t_ac2);
      digitalWrite(gruesa,LOW);
      digitalWrite(fina, LOW);
      delay(t_ac3);
      peso = print_peso();
    }
  }
}
boolean regresar(){
  TECLA = teclado.getKey();
  switch(TECLA){
    case '*':        
      digitalWrite(fina, LOW);
      digitalWrite(gruesa, LOW);   
      digitalWrite(m_abre, LOW);
      digitalWrite(m_cierra, LOW);   
      lcd.clear();
      lcd.print("   JACS MAQUINAS");
      lcd.setCursor(3, 3);
      lcd.print("Finalizando...");  
      delay(1500); 
      EEPROM.put( 140, contador );
      Serial.println("DETENEMOS");
      delay(500);      
      return true;
    case 'C':
      auto_inercia();
      return false;     
    default:
      return false;
  }
}
boolean auto_inercia(){ 
  Serial.println("entra");   
  inercia=inercia+get_peso()-s_peso;
  lcd.setCursor(19, 0);
  lcd.print("C");
  delay(1000);
  lcd.setCursor(19, 0);
  lcd.print(" ");
  delay(1000);    
}