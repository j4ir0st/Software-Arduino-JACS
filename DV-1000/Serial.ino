char dato;
char serial(){
  if (Serial.available())  //Comprobamos si hay datos desde VB hacia Arduino
  {
    dato=Serial.read();  //Guardamos el dato recibido
    if (dato=='S'){     
      dato=Serial.read();  //Guardamos el dato recibido
      switch(dato)
      {
        case 'V':           
          dato=Serial.read();
          switch(dato)
          {
            case 'P':
              s_peso=Serial.parseInt();
              EEPROM.put( 20, s_peso ); 
              loop();                   
              break;
            case 'V':
              v_fina=Serial.parseInt();
              EEPROM.put( 80, v_fina ); 
              loop();                   
              break;
            case 'I':
              inercia=Serial.parseInt();
              EEPROM.put( 40, inercia ); 
              loop();                   
              break;
          }             
          break;              
        case 'C':
          dato=Serial.read();
          switch(dato)
            {
              case '1':
                return('1');                  
                break;
              case '*':
                return('*');               
                break;
              case 'D':
                return('D');               
                break;
            }         
          break;
      }
    } 
    
      
  }
}
