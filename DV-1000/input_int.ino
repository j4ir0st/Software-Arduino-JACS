int input_int(String pregunta, double val_min, double val_max, String unidad){
 ini:
    long valor_i = -1;
    String valor_s = "";
    lcd.clear();
    lcd.setCursor(10 - ((pregunta.length() / 2)), 0);    
    lcd.print(pregunta);
    if (unidad.length() > 0) {
      lcd.setCursor(9 - ((unidad.length() / 2)), 1);    
      lcd.print("(" + unidad + ")");    
    }
    lcd.setCursor(0, 3);
    lcd.print("*)Regresar D)Aceptar");

    // Limpia teclas residuales del búfer para evitar lecturas no deseadas
    while(teclado.getKey() != NO_KEY);
    TECLA = NO_KEY;

    while (1){
      TECLA = teclado.getKey();
      if (TECLA != NO_KEY){
        if (TECLA >= '0' && TECLA <= '9'){
          if (valor_s.length() < 6){
            valor_s += TECLA;
            valor_i = valor_s.toInt();   
            lcd.setCursor(2, 2);
            lcd.print("                ");
            lcd.setCursor(10 - (valor_s.length() / 2), 2);
            lcd.print(valor_i);
            if (unidad.length() > 0) {
              lcd.print(" ");
              lcd.print(unidad); 
            }
          } 
        }
        else if (TECLA == 'D'){
          if (val_max == 0){
            return 1; // Para mensajes como "COLOQUE LA PESA" donde solo se pulsa D      
          }
          if (valor_i < val_min || valor_i > val_max){
            valor_incorrecto(val_min, val_max);
            goto ini;
          }
          else{
            valor_ingresado(valor_s, unidad);
            return valor_i;
          }          
        }
        else if (TECLA == '*'){
          return -1; // Regresar / Cancelar   
        }
      }
    }
}
double input_clave(String pregunta, double val_min, double val_max, String unidad){
 ini:
    long valor_i = -1;
    String valor_s = "";
    String valor_s2 = "";
    lcd.clear();
    lcd.setCursor(10 - ((pregunta.length() / 2)), 0);
    lcd.print(pregunta);
    lcd.setCursor(0, 3);
    lcd.print("*)Regresar D)Aceptar");
   
    while(teclado.getKey() != NO_KEY);
    TECLA = NO_KEY;

    while (1){
      TECLA = teclado.getKey();
      if (TECLA != NO_KEY){
        if (TECLA >= '0' && TECLA <= '9'){
          if (valor_s.length() < 6){
            valor_s += TECLA;
            valor_s2 += "*";
            valor_i = valor_s.toInt();   
            lcd.setCursor(2, 2);
            lcd.print("                ");
            lcd.setCursor(10 - (valor_s2.length() / 2), 2);
            lcd.print(valor_s2);
          } 
        }
        else if (TECLA == 'D'){          
          if (valor_i < val_min || valor_i > val_max){
            valor_incorrecto(val_min, val_max);
            goto ini;
          }
          else{
            return valor_i;
          }          
        }
        else if (TECLA == '*'){
          return -1;
        }
      }
    }   
}