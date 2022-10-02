void scr_menu(){
  switch(var_menu){
    case 0://TIEMPO DE SELLADO
      lcd.clear();
      lcd.print("  TIEMPO SELLADO  A");
      lcd.setCursor(0, 1);
      lcd.print("1)TIEMPO(" + String(t_sellado)+")");
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 1://ON OFF MORDAZAS
      lcd.clear();
      lcd.print("      MORDAZAS    A");
      lcd.setCursor(0, 1);  
      lcd.print("1)I(" + String(get_estado(7))+")");
      if(tipo_maq==1){
      lcd.setCursor(10, 1);  
      lcd.print("3)D(" + String(get_estado(8))+")");}     
      lcd.setCursor(0, 2);
      lcd.print("2)E(" + String(get_estado(9))+")");
      lcd.setCursor(10, 2);
      lcd.print("4)I(" + String(get_estado(10))+")");    
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio    D)Set B");
      flechas();      
      break;
    case 2://VER TEMPERATURAS
      lcd.clear();
      lcd.print(" VER TEMPERATURAS A");
      lcd.setCursor(0, 1);  
      lcd.print("I(" + String(get_sset(7)) + "-" + String(get_stemp(7)) + ")");
      if(tipo_maq==1){
      lcd.setCursor(10, 1);  
      lcd.print("D(" + String(get_sset(8)) + "-" + String(get_stemp(8)) + ")");}      
      lcd.setCursor(0, 2);
      lcd.print("E(" + String(get_sset(9)) + "-" + String(get_stemp(9)) + ")");
      lcd.setCursor(10, 2);
      lcd.print("I(" + String(get_sset(10)) + "-" + String(get_stemp(10)) + ")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio    D)Set B");
      flechas();     
      break;
    case 3://SET TEMPERATURAS
      lcd.clear();
      lcd.print(" SET TEMPERATURAS A");
      lcd.setCursor(0, 1);  
      lcd.print("1)SI(" + String(get_sset(7)) + ")");
      if(tipo_maq==1){
      lcd.setCursor(10, 1);  
      lcd.print("3)SD(" + String(get_sset(8)) + ")");}     
      lcd.setCursor(0, 2);
      lcd.print("2)IE(" + String(get_sset(9)) + ")");
      lcd.setCursor(10, 2);
      lcd.print("4)II(" + String(get_sset(10)) + ")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas();      
      break;
    case 4://MORDAZA SUPERIOR IZQUIERDA
      lcd.clear();
      lcd.print("  MORDAZA SUP IZQ A");
      lcd.setCursor(0, 1);
      lcd.print("1)(" +get_estado(7)+")");
      lcd.setCursor(10, 1);
      lcd.print("3)AT (" +get_at(7)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)GET(" + String(get_stemp(7)) +")");
      lcd.setCursor(10, 2);
      lcd.print("4)SET(" + String(get_sset(7)) + ")");            
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 5://MORDAZA SUPERIOR DERECHA
      if(tipo_maq==1){
        lcd.clear();
        lcd.print("  MORDAZA SUP DER A");
        lcd.setCursor(0, 1);
        lcd.print("1)(" +get_estado(8)+")");
        lcd.setCursor(10, 1);
        lcd.print("3)AT (" +get_at(8)+")");
        lcd.setCursor(0, 2);
        lcd.print("2)GET(" + String(get_stemp(8)) +")");
        lcd.setCursor(10, 2);
        lcd.print("4)SET(" + String(get_sset(8)) + ")");            
        lcd.setCursor(0, 3);
        lcd.print("*)Inicio          B");
        flechas();
        break;
      }
      else{
        if(TECLA=='A'){
            var_menu--;
        }
        else{
          var_menu++;
        }
        opc_menu();        
      }
      break;
    case 6://MORDAZA INFERIOR EXTERIOR
      lcd.clear();
      lcd.print("  MORDAZA INF EXT A");
      lcd.setCursor(0, 1);
      lcd.print("1)(" +get_estado(9)+")");
      lcd.setCursor(10, 1);
      lcd.print("3)AT (" +get_at(9)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)GET(" + String(get_stemp(9)) +")");
      lcd.setCursor(10, 2);
      lcd.print("4)SET(" + String(get_sset(9)) + ")");            
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas();
      break;
    case 7://MORDAZA INFERIOR INTERIOR
      lcd.clear();
      lcd.print("  MORDAZA INF INT A");
      lcd.setCursor(0, 1);
      lcd.print("1)(" +get_estado(10)+")");
      lcd.setCursor(10, 1);
      lcd.print("3)AT (" +get_at(10)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)GET(" + String(get_stemp(10)) +")");
      lcd.setCursor(10, 2);
      lcd.print("4)SET(" + String(get_sset(10)) + ")");            
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas();
      break;
    case 8://ARRASTRE
      lcd.clear();
      lcd.print("   AR ARRASTRE    A");
      lcd.setCursor(0, 1);
      lcd.print("1)ARRAS.(" + String(ar_arrastre)+")");
      lcd.setCursor(14, 1);
      lcd.print("3)MT"); 
      lcd.setCursor(0, 2);
      lcd.print("2)PRE A.(" + String(ar_prearrastre)+")"); 
      lcd.setCursor(14, 2);
      lcd.print("4)MAR");     
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas();   
      break;
    case 9://AR DOSIFICADOR
      lcd.clear();
      lcd.print("  AR DOSIFICADOR  A");
      lcd.setCursor(0, 1);
      lcd.print("1)DOS. SUBE   (" + String(ar_doss)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)DOS. BAJA   (" + String(ar_dosb)+")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 10://AR PURGA
      lcd.clear();
      lcd.print("     AR PURGA     A");
      lcd.setCursor(0, 1);
      lcd.print("1)PUR. SUBE   (" + String(ar_purs)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)PUR. BAJA   (" + String(ar_purb)+")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 11://AR ACTUADOR
      lcd.clear();
      lcd.print("    AR ACTUADOR   A");
      lcd.setCursor(0, 1);
      lcd.print("1)A. DOSIFICA (" + String(ar_actd)+")");
      lcd.setCursor(0, 2);
      lcd.print("2)A. CARGA    (" + String(ar_actc)+")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 12://AR MORDAZAS
      lcd.clear();
      lcd.print("    AR MORDAZAS   A");
      lcd.setCursor(0, 1);
      lcd.print("1)CIERRA(" + String(ar_morc)+")");
      lcd.setCursor(13, 1);
      if (fc_mor==1){
        lcd.print("3)(On)");     
      }
      else{
        lcd.print("3)(Off)");     
      }       
      lcd.setCursor(0, 2);
      lcd.print("2)ABRE  (" + String(ar_mora)+")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 13://SECUENCIA
      lcd.clear();
      lcd.print("    SECUENCIA     A");
      lcd.setCursor(0, 1);
      if (sec==0){
        lcd.print("1)DOS-AVA-SEL");
      }
      else{
        lcd.print("1)SEL Y DOS");
      }         
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;      
    case 14://MODO DOSIFICADOR
      lcd.clear();
      lcd.print(" MODO DOSIFICADOR A");
      lcd.setCursor(0, 1);
      if (m_dos==0){
        lcd.print("1)MEDIO");
      }
      else{
        lcd.print("1)COMPLETO");
      }         
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas();
      break;
    case 15://TACA
      lcd.clear();
      lcd.print("  SENSOR DE TACA  A");
      lcd.setCursor(0, 1);
      if (s_taca==1){
        lcd.print("1)ESTADO(On) 3)MTACA");
      }
      else{
        lcd.print("1)ESTADO(Off)3)MTACA");
      }
      lcd.print("*)Inicio          B");
      flechas();   
      break;
    case 16://SALIDAS
      lcd.clear();
      lcd.print("      SALIDAS     A");
      lcd.setCursor(0, 1);
      lcd.print("1)MO(" + String(digitalRead(mordazas)) +")");
      lcd.setCursor(7, 1);
      lcd.print("2)AC(" + String(digitalRead(actuador))+")");
      lcd.setCursor(14, 1);
      lcd.print("3)DS(" + String(digitalRead(dos_sube))+")");
      lcd.setCursor(0, 2);
      lcd.print("4)DB(" + String(digitalRead(dos_baja))+ ")");
      lcd.setCursor(7, 2);
      lcd.print("5)AR(" + String(digitalRead(arrastre))+ ")");            
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 17://ENTRADAS
      lcd.clear();
      lcd.print("      ENTRADAS    A");
      lcd.setCursor(1, 1);
      lcd.print("MO(" + String(mo()) +")");
      lcd.setCursor(7, 1);
      lcd.print("FD(" + String(fd())+")");
      lcd.setCursor(13, 1);
      lcd.print("SD(" + String(sd())+")");
      lcd.setCursor(1, 2);
      lcd.print("TA(" + String(ta())+ ")");
      lcd.setCursor(7, 2);
      lcd.print("PE(" + String(pe())+ ")");   
      lcd.setCursor(13, 2); 
      lcd.print("AR(" + String(ar())+ ")");    
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break;
    case 18://CONTADOR
      lcd.clear();
      lcd.print("      CONTADOR    A");
      lcd.setCursor(10-(String(contador).length()/2), 2);
      lcd.print("("+String(contador)+")");      
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio          B");
      flechas(); 
      break; 
    case 19://FACTORY RESET
      lcd.clear();
      lcd.print(" RESET DE FABRICA A");
      lcd.setCursor(0, 1);
      lcd.print("9)RESET");
      lcd.setCursor(0, 3);       
      lcd.print("*)Inicio          B");
      flechas(); 
      break; 
    case 8662://TIPO DE MAQUINA
      lcd.clear();
      lcd.print("  TIPO DE MAQUINA");
      lcd.setCursor(0, 1);
      if (tipo_maq==0){
        lcd.print("1)SLSC-MS 2021LC");
      }
      else{
        lcd.print("1)SLSO-MS 2021LC");
      }         
      lcd.setCursor(0, 3);
      lcd.print("*)Inicio");  
  }
}

void act_temp(){
  lcd.setCursor(6, 1);  
  lcd.print(String(get_stemp(7)));
  lcd.setCursor(16, 1);  
  lcd.print(String(get_stemp(8)));      
  lcd.setCursor(6, 2);
  lcd.print(String(get_stemp(9)));
  lcd.setCursor(16, 2);
  lcd.print(String(get_stemp(10)));      
}
void act_temp1(int id){ 
  lcd.setCursor(6, 2);  
  lcd.print(String(get_stemp(id)));    
}
void flechas(){
  lcd.setCursor(19,0);      
  lcd.write((byte)1);
  lcd.setCursor(19,3);
  lcd.write((byte)2); 
}
