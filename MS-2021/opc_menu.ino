int val=0;
void opc_menu(){
  scr_menu();
  switch(var_menu){
      case 0:
        for(int i=0;i<1;i){
          TECLA = teclado.getKey();
          if (TECLA){
            switch(TECLA){
              case '1':      
                val=input_int("TIEMPO DE SELLADO",0,9000,"mseg");
                if(val!=-1){
                  EEPROM.put( 5, val );   
                  t_sellado=val;                    
                }
                opc_menu();
                break;
              case '*':          
                scr_inicio();
                break;   
              } 
              ab(TECLA);                
            } 
            delay(200);           
          }  
        break;
      case 1:
        for(int i=0;i<1;i){
          switch(tec()){
            case '1': 
              if (get_estado(7).equals("On")){
                set_estado(7,"Off");
              }
              else{set_estado(7,"On");}
              opc_menu();
              break;
            case '3':
               if (get_estado(8).equals("On")){
                set_estado(8,"Off");
              }
              else{set_estado(8,"On");}
              opc_menu();
              break;
            case '2':
              if (get_estado(9).equals("On")){
                set_estado(9,"Off");
              }
              else{set_estado(9,"On");}
              opc_menu();
              break;
            case '4':
              if (get_estado(10).equals("On")){
                set_estado(10,"Off");
              }
              else{set_estado(10,"On");}
              opc_menu();
              break;
            case '5':
              for (int j=7; j<11;j++){
                set_estado(j,"On");
              }
              opc_menu();
              break;
            case '6':
              for (int j=7; j<11;j++){
                set_estado(j,"Off");
              }
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break; 
          }
          ab(TECLA);
          delay(200);
        }
        break;
      case 2://VER TEMPERATURAS
          con=0;
          for(int i=0;i<1;i){
            if(con==25){
              act_temp();
              con=0;
            }
            con++;
          switch(tec()){
            case 'D':      
              var_menu=3;
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break;   
          } 
          ab(TECLA);
          delay(200);             
        } 
        break;
      case 3://SET TEMPERATURAS
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':      
              val=input_int("INGRESE TEMPERATURA",0,200,"C");
              if (val!=-1){
                set_temp(7,val);
              }
              opc_menu();
              break;
            case '3':          
              val=input_int("INGRESE TEMPERATURA",0,200,"C");
              if (val!=-1){
                set_temp(8,val);
              }
              opc_menu();
              break;  
            case '2':          
              val=input_int("INGRESE TEMPERATURA",0,200,"C");
              if (val!=-1){
                set_temp(9,val);
              }
              opc_menu();
              break; 
            case '4':          
              val=input_int("INGRESE TEMPERATURA",0,200,"C");
              if (val!=-1){
                set_temp(10,val);
              }
              opc_menu();
              break; 
            case '*':          
              scr_inicio();
              break;  
          } 
          ab(TECLA);
          delay(200);            
        }
        break;
      case 4://MORDAZA SUPERIOR IZQUIERDA
        opc_mordazas(7);
        break;
      case 5://MORDAZA SUPERIOR DERECHA
        opc_mordazas(8);  
        break;
      case 6://MORDAZA INFERIOR EXTERNA
        opc_mordazas(9);
        break;
      case 7://MORDAZA INFERIOR INTERNA
        opc_mordazas(10);
        break;
      case 8://ARRASTRE
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              val=input_int("ANTIREBOTE AR",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 10, val );
                ar_arrastre=val;                    
              }
              opc_menu();          
              break;
            case '2':
              val=input_int("PREAVANCE",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 85, val );
                ar_prearrastre=val;                    
              }
              opc_menu();          
              break;
            case '3':
              arrastrar_taca();
              break;
            case '4':
              arrastrar_ar();
              break;
            case '5':
              arrastrar_par();
              break;
            case '*':          
              scr_inicio();
              break; 
            
          }
          ab(TECLA);           
          delay(200);         
        } 
        break;
      case 9://AR DOSIFICADOR
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              val=input_int("ANTIREBOTE DS",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 15, val );
                ar_doss=val;                    
              }
              opc_menu();
              break;
            case '2':
              val=input_int("ANTIREBOTE DB",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 20, val );
                ar_dosb=val;                    
              }
              opc_menu();
              break;
            case '3':
              dosificar();
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        } 
        break;
      case 10://AR PURGA
       for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              val=input_int("ANTIREBOTE PS",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 25, val );
                ar_purs=val;                    
              }
              opc_menu();
              break;
            case '2':
              val=input_int("ANTIREBOTE PB",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 30, val );
                ar_purb=val;                    
              }
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        } 
        break;
      case 11://AR ACTUADOR
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              val=input_int("ANTIREBOTE AD",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 35, val );
                ar_actd=val;                    
              }
              opc_menu();
              break;
            case '2':
              val=input_int("ANTIREBOTE AC",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 40, val );
                ar_actc=val;                    
              }
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        } 
        break;
      case 12://AR MORDAZAS
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              val=input_int("ANTIREBOTE MC",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 45, val );
                ar_morc=val;                    
              }
              opc_menu();
              break;
            case '2':
              val=input_int("ANTIREBOTE MA",0,9000,"mseg");
              if(val!=-1){
                EEPROM.put( 50, val );
                ar_mora=val;                    
              }
              opc_menu();
              break;
            case '3':
              if(fc_mor==1){
                fc_mor=0;
                EEPROM.put( 55, fc_mor );
                lcd.setCursor(16, 1);
                lcd.print("    ");
                lcd.setCursor(16, 1);
                lcd.print("Off)");
              }
              else{
                fc_mor=1;
                EEPROM.put( 55, fc_mor );
                lcd.setCursor(16, 1);
                lcd.print("    ");
                lcd.setCursor(16, 1);
                lcd.print("On)");
              }              
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        } 
        break;
      case 13://SECUENCIA
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              if(sec==0){
                sec=1;
                EEPROM.put( 70, sec );                    
              }
              else{
                sec=0;
                EEPROM.put( 70, sec );
              }
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        } 
        break;
      case 14://MODO DOSIFICADOR
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              if(m_dos==0){
                m_dos=1;
                EEPROM.put( 75,m_dos );                    
              }
              else{
                m_dos=0;
                EEPROM.put( 75, m_dos );
              }
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break;         
          } 
          ab(TECLA);
          delay(200);         
        }
        break;
      case 15://TACA
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              if(s_taca==1){
                s_taca=0;
                EEPROM.put( 60, s_taca );
                lcd.setCursor(9, 1);
                lcd.print("    ");
                lcd.setCursor(9, 1);
                lcd.print("Off)");
              }
              else{
                s_taca=1;
                EEPROM.put( 60, s_taca );
                lcd.setCursor(9, 1);
                lcd.print("    ");
                lcd.setCursor(9, 1);
                lcd.print("On)");
              }              
              break;
            case '*':          
              scr_inicio();
              break;
          }
          ab(TECLA);
          delay(200);  
        }
        break;
      case 16://SALIDAS
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              salida(arrastre);
              opc_menu();
              break;
            case '2':
              salida(dos_sube);
              opc_menu();
              break;
            case '3':
              salida(dos_baja);
              opc_menu();
              break;
            case '4':
              salida(actuador);
              opc_menu();
              break;
            case '5':
              salida(mordazas);
              opc_menu();
              break;
            case '6':
              salida(AUX1);
              opc_menu();
              break;
            case '7':
              salida(AUX2);
              opc_menu();
              break;
            case '8':
              salida(AUX3);
              opc_menu();
              break;
            case '*':          
              scr_inicio();
              break; 
          }
          ab(TECLA);
          delay(200);         
        }        
        break;
      case 17://ENTRADAS
        for(int i=0;i<1;i){
          lcd.setCursor(1, 1);
          lcd.print("MO(" + String(digitalRead(fc_mordazas)) +")");
          lcd.setCursor(7, 1);
          lcd.print("FD(" + String(digitalRead(fc_dosificador))+")");
          lcd.setCursor(13, 1);
          lcd.print("SD(" + String(digitalRead(sw_dosificador))+")");
          lcd.setCursor(1, 2);
          lcd.print("TA(" + String(digitalRead(taca))+ ")");
          lcd.setCursor(7, 2);
          lcd.print("PE(" + String(digitalRead(PE))+ ")");
          lcd.setCursor(13, 2);
          lcd.print("AR(" + String(digitalRead(AR))+ ")");
          switch(tec()){            
            case '*':          
              scr_inicio();
              break; 
          }
          ab(TECLA);          
          delay(200);         
        } 
        break;
      case 18://CONTADOR
        for(int i=0;i<1;i){
          TECLA = teclado.getKey();
          if (TECLA){
            switch(TECLA){
              case '*':          
                scr_inicio();
                break; 
            }
            ab(TECLA);
          } 
          delay(200);         
        } 
        break;
      case 19://RESET
        for(int i=0;i<1;i){
          switch(tec()){
            case '9':
              reset_valores();
              cargar_valores();
              lcd.setCursor(7, 1);
              lcd.print("(LISTO)");
              break;
            case '*':          
              scr_inicio();
              break; 
          }
          ab(TECLA);         
          delay(200);          
        } 
        break; 
      case 8661://RESET CONTADOR
        reset_contador();
        mensaje("      RESET OK");
        scr_inicio();
        break;
      case 8662://TIPO DE MAQUINA
        for(int i=0;i<1;i){
          switch(tec()){
            case '1':
              if (tipo_maq==0){
                tipo_maq=1;
                lcd.print("1)SLSO MS LC");
              }
              else{
                tipo_maq=0;
                lcd.print("1)SLSC MS LC");
              }  
              break;
            case '*': 
              EEPROM.put(90,tipo_maq );         
              scr_inicio();
              break; 
          }         
        }        
        scr_inicio();
        break;
        
      default:
        mensaje("  ERROR DE COMANDO");
        scr_inicio();
        break;
  }
}
void ab(char TECLA){
  if (TECLA){
   switch(TECLA){               
    case 'A':
      if (var_menu==0){
        var_menu=19;
      }
      else{
        var_menu--;
      } 
      opc_menu();   
      break;
    case 'B':
      if (var_menu==19){
        var_menu=0;
      }
      else{
        var_menu++;
      }    
      opc_menu();            
      break;
    case 'C':
      val=input_int("INGRESE COMANDO",1,9999,"");
      var_menu=val;
      opc_menu();
      break;
   }
 }
}
void opc_mordazas(int id){
  con=0;
    for(int i=0;i<1;i){
      if(con==10){
        act_temp1(id);
        con=0;
      }
      con++;
    switch(tec()){
      case '1': 
        if (get_estado(id).equals("On")){
          set_estado(id,"Off");
        }

        else{
On:     set_estado(id,"On");}
        //opc_menu();  
        lcd.setCursor(3, 1);
        lcd.print("    ");
        lcd.setCursor(3, 1);
        lcd.print(get_estado(id)+")");
        //lcd.setCursor(10, 1);
        //lcd.print("3)AT (" +get_at(7)+")");             
        break;
      case '2': 
        act_temp1(id);   
        break;
      case '3':  
        if (get_at(id).equals("On")){
          set_at(id,"Off");
        }
        else{
          set_at(id,"On");
        }
        lcd.setCursor(16, 1);
        lcd.print("    ");
        lcd.setCursor(16, 1);
        lcd.print(get_at(id)+")");  
        goto On; 
        break;
      case '4':  
        val=input_int("INGRESE TEMPERATURA",0,200,"C");
        if (val!=-1){
          set_temp(id,val);
        }
        opc_menu(); 
        break;
      case '*':          
        scr_inicio();
        break;   
    } 
    ab(TECLA);
    delay(200);              
  } 
}
void salida(int pin){
  pinMode(pin,OUTPUT); 
  digitalWrite(pin,!digitalRead(pin));
}
void salida_on(int pin){
  pinMode(pin,OUTPUT); 
  digitalWrite(pin,HIGH);
}
void salida_off(int pin){
  pinMode(pin,OUTPUT); 
  digitalWrite(pin,LOW);
}
