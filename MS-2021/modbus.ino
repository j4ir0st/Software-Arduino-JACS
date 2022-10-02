void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}
void postTransmission()
{
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}



int get_temp(int id){
  int temp=0;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x41,1);
  temp = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  if (temp>=9999){
    temp=999;
  }
  return(temp);
}
String get_stemp(int id){
  int temp=0;
  String s_temp;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x41,1);
  temp = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  if (temp>=9999){
    temp=999;
  }
  
  if (temp<=9){
    s_temp="00"+String(temp);
    return(s_temp);
  }
  else{
    if (temp<=99){
      s_temp="0"+String(temp);
      return(s_temp);
    }
    else{
      if (temp<=999){
        s_temp=String(temp);
        return(s_temp);
      }
      else{        
        return("999");        
      }      
    }
  }  
}
int get_set(int id){
  int temp=0;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x40,1);
  temp = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  return(temp);  
}
String get_sset(int id){
  int temp=0;
  String s_temp;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x40,1);
  temp = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  if (temp<=9){
    s_temp="00"+String(temp);
    return(s_temp);
  }
  else{
    if (temp<=99){
      s_temp="0"+String(temp);
      return(s_temp);
    }
    else{
      s_temp=String(temp);
      return(s_temp);
    }
  } 
}
String get_estado(int id){
  int val=0;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x24,1);
  val = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  if(val==0){
    return("On");
  }
  if(val==1){
    return("Off");
  }  
}
int set_estado(int id,String val){
  if (id==8 && tipo_maq==0){
  }
  else{
    node.begin(id,Serial1);
    if(val.equals("On")){
      node.writeSingleRegister(0x24,0);
    }
    if(val.equals("Off")){
      node.writeSingleRegister(0x24,1);
    }
    delay(10);
  }
}






String get_at(int id){
  int val=0;
  node.begin(id,Serial1);
  node.clearResponseBuffer();
  delay(10);
  node.readHoldingRegisters(0x11,1);
  val = node.getResponseBuffer(0); 
  node.clearResponseBuffer();
  if(val==0){
    return("Off");
  }
  if(val==1){
    return("On");
  }  
}
int set_at(int id,String val){
  node.begin(id,Serial1);
  node.writeSingleRegister(0x15,20);
  
  if(val.equals("On")){
    node.writeSingleRegister(0x11,1);
  }
  if(val.equals("Off")){
    node.writeSingleRegister(0x11,0);
  }
  delay(10);
}




int set_temp(int id,int temperatura){
  node.begin(id,Serial1);
  node.writeSingleRegister(0x40,temperatura);  
  delay(10);
}
