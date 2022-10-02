double input_dbl(String pregunta,double val_min,double val_max, String unidad){
 ini:
    double valor_d=0;
    String valor_s;
    String valor_s2;
    lcd.clear();
    lcd.setCursor(10-((pregunta.length()/2)), 0);
    lcd.print(pregunta);
    lcd.setCursor(10-((unidad.length()/2)), 1);    
    lcd.print("("+unidad+")");
    lcd.setCursor(8, 2);
    lcd.print("0.00");
    lcd.setCursor(0, 3);
    lcd.print("*)Regresar D)Aceptar");
   
    for (int i=0;i<1;i){
    TECLA = teclado.getKey();
      if (TECLA){
        if (TECLA >= '0' && TECLA <='9' ){
          if (valor_s.length()<(String(val_max,2).length())-1){
            valor_s+=TECLA;
            valor_d=String(valor_s).toInt();
            valor_d=(valor_d/100);
            valor_s2=String(valor_d,2);
            if(valor_s2.length()<3){
              lcd.setCursor(10-(valor_s2.length()/2), 2);
            }
            else{
              lcd.setCursor(10-(valor_s2.length()-2), 2);
            }
            lcd.print(valor_d);
            lcd.print(" ");
            lcd.print(unidad); 
          } 
        }
        if(TECLA=='D'){          
          if(valor_d<val_min || valor_d>val_max){
            valor_incorrecto(val_min,val_max);
            goto ini;
          }
          else{
            valor_ingresado(valor_s2,unidad);
            return(valor_d);
          }          
        }
        if(TECLA=='*'){
          return(-1);
        }
      }
    }   
}
