int mo(){
  return(digitalRead(fc_mordazas));
}
int fd(){
  return(digitalRead(fc_dosificador));
}
int sd(){
  return(digitalRead(sw_dosificador));
}
int ta(){
  return(digitalRead(taca));
}
int pe(){
  return(digitalRead(PE));
}
int ar(){
  return(digitalRead(AR));
}
