void opc_9(){
ini:  
  /* Imprime pantalla de menú reset de fábrica */
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("RESET DE FABRICA A");
  lcd.setCursor(0, 1);
  lcd.print("1)RESET");
  lcd.setCursor(0, 2);
  lcd.print("2)GUARDAR");
  lcd.setCursor(14, 1);
  lcd.print("3)RST");
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar         B");
  lcd.setCursor(19, 1);
  lcd.write(1);                 // imprime flecha arriba
  lcd.setCursor(19, 2);         
  lcd.write(2);                 // imprime flecha abajo
  /* -------------------------------------------- */
  switch(tec()){
    case '1':
      if (msgbox_yes_no("RESET DE FABRICA") == 1){
        lcd.clear();
        lcd.setCursor(3, 2);
        lcd.print("reseteando...");  
        reset_valores();
        delay(2000);
        lcd.clear();
        lcd.setCursor(4, 2);
        lcd.print("cargando...");  
        cargar_valores();
        delay(2000); 
        lcd.setCursor(3, 2);
        lcd.print("Reseteo listo");
        delay(500);
        return;
      }
      goto ini;
    case '2':
      guardar();
      lcd.clear();
      lcd.setCursor(3, 2);
      lcd.print("Guardado!");
      delay(1000);
      goto ini;
    case '3':
      if (msgbox_yes_no("RESTAURAR DATOS") == 1){
        lcd.clear();
        lcd.setCursor(3, 2);
        lcd.print("restaurando...");
        restaurar();
        delay(2000); 
        lcd.setCursor(3, 2);
        lcd.print("Restauración lista");
        delay(500);
      }
      goto ini;
    case 'A':
      opc_8();
      return;  
    case 'B':
      opc_1();
      return;
    case '*':
      return;
    default:
      goto ini;
  }   
}
void reset_valores(){ 
  EEPROM.put( 0, 10 );                            // dosis en ml
  EEPROM.put( 10, 10 );                           // diámetro del embolo (mm)
  EEPROM.put( 20, 4 );                            // paso de tornillo (mm)
  EEPROM.put( 30, 1 );                            // pulsos x revolución
  EEPROM.put( 40, 1 );                            // modo de trabajo (Manual = 1 o Automático = 2)
  EEPROM.put( 50, 0 );                            // var_longitud - no me acuerdo (by tono)          
  EEPROM.put( 60, 500 );                          // velocidad de descarga (rpm)
  var_velocidad = (2000 - var_velocidad_d) + 40;  // velocidad en función de velocidad de descarga 
  EEPROM.put( 70, 1 );                            // delay
  EEPROM.put( 80, 0 );                            // para calcular cuantos pulsos se necesita por dosis
  EEPROM.put( 90, 0 );                            // error
  EEPROM.put( 100, 500 );                         // dosis máxima
  EEPROM.put( 110, 1 );                           // delay en modo automático
  EEPROM.put( 120, 0 );                           // repetir dosis
  EEPROM.put( 130, 100 );                         // velocidad de carga (rpm)
  EEPROM.put( 140, 1 );                           // delay en carga
  EEPROM.put( 150, 3000 );                        // velocidad máxima
  EEPROM.put( 160, 0 );                           // contador
}
void guardar(){ 
  EEPROM.put( 200, var_dosis );                   // dosis en ml
  EEPROM.put( 210, diametro_embolo );             // diámetro del embolo (mm)
  EEPROM.put( 220, var_paso );                    // paso de tornillo (mm)
  EEPROM.put( 230, pulsos_rev );                  // pulsos x revolución
  EEPROM.put( 240, var_modo );                    // modo de trabajo (Manual = 1 o Automático = 2)
  EEPROM.put( 250, var_longitud );                // var_longitud - no me acuerdo (by tono)          
  EEPROM.put( 260, var_velocidad_d );             // velocidad de descarga (rpm)
  var_velocidad = (2000 - var_velocidad_d) + 40;     // velocidad en función de velocidad de descarga 
  EEPROM.put( 270, var_delay );                   // delay
  EEPROM.put( 280, pulsos_dosis );                // para calcular cuantos pulsos se necesita por dosis
  EEPROM.put( 290, var_error );                   // error
  EEPROM.put( 300, var_dosis_max );               // dosis máxima
  EEPROM.put( 310, var_delay_aut );               // delay en modo automático
  EEPROM.put( 320, var_repetir );                 // repetir dosis
  EEPROM.put( 330, var_velocidad_c );             // velocidad de carga (rpm)
  EEPROM.put( 340, var_delay_c );                 // delay en carga
  EEPROM.put( 350, var_velocidad_max );           // velocidad máxima
  EEPROM.put( 360, contador );                    // contador
}
void restaurar(){
  EEPROM.get( 200, var_dosis );                   // dosis en ml
  EEPROM.get( 210, diametro_embolo );             // diámetro del embolo (mm)
  EEPROM.get( 220, var_paso );                    // paso de tornillo (mm)
  EEPROM.get( 230, pulsos_rev );                  // pulsos x revolución
  EEPROM.get( 240, var_modo );                    // modo de trabajo (Manual = 1 o Automático = 2)
  EEPROM.get( 250, var_longitud );                // var_longitud - no me acuerdo (by tono)          
  EEPROM.get( 260, var_velocidad_d );             // velocidad de descarga (rpm)
  var_velocidad = (2000 - var_velocidad_d) + 40;     // velocidad en función de velocidad de descarga 
  EEPROM.get( 270, var_delay );                   // delay
  EEPROM.get( 280, pulsos_dosis );                // para calcular cuantos pulsos se necesita por dosis
  EEPROM.get( 290, var_error );                   // error
  EEPROM.get( 300, var_dosis_max );               // dosis máxima
  EEPROM.get( 310, var_delay_aut );               // delay en modo automático
  EEPROM.get( 320, var_repetir );                 // repetir dosis
  EEPROM.get( 330, var_velocidad_c );             // velocidad de carga (rpm)
  EEPROM.get( 340, var_delay_c );                 // delay en carga
  EEPROM.get( 350, var_velocidad_max );           // velocidad máxima
  EEPROM.get( 360, contador );                    // contador
}
int msgbox_yes_no(String pregunta){
ini:
  lcd.clear(); 
  lcd.setCursor(10 - ((pregunta.length() / 2)), 0);    
  lcd.print(pregunta);
  lcd.setCursor(8, 1);
  lcd.print("1)SI");
  lcd.setCursor(8, 2);
  lcd.print("2)NO");
  lcd.setCursor(0, 3);       
  lcd.print("*)regresar");    
  switch(tec()){        
    case '1':      
      return(1);
    case '2':
      return(0);
    case '*':        
      return(-1);
    default:
      goto ini;
  }  
}
