int input_int(String pregunta,double val_min,double val_max, String unidad){
 ini:
    int valor_i=-1;
    String valor_s;
    String valor_s2;
    lcd.clear();
    lcd.setCursor(10-((pregunta.length()/2)), 0);    
    lcd.print(pregunta);
    lcd.setCursor(9-((unidad.length()/2)), 1);    
    lcd.print("("+unidad+")");    
    lcd.setCursor(0, 3);
    lcd.print("*)Regresar D)Aceptar");
   
    for (int i=0;i<1;i){
    TECLA = teclado.getKey();
      if (TECLA){
        if (TECLA >= '0' && TECLA <='9' ){
        //lcd.setCursor(5-(valor_s.length()/2), 1);
          if (valor_s.length()<(String(val_max,2).length())-1){
            valor_s+=TECLA;
            valor_i=String(valor_s).toInt();   
            lcd.setCursor(10-(valor_s.length()/2), 2);
            lcd.print(valor_i);
            //lcd.print(" ");
            //lcd.print(unidad); 
          } 
        }
        if(TECLA=='D'){          
          if(valor_i<val_min || valor_i>val_max){
            valor_incorrecto(val_min,val_max);
            goto ini;
          }
          else{
            valor_ingresado(valor_s,unidad);
            return(valor_i);
          }          
        }
        if(TECLA=='*'){
          return(-1);
        }
      }
    }   
}
