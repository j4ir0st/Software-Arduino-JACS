void descargar(){
  estado = 0;
  digitalWrite(m_abre, HIGH);
  delay(d1);
  digitalWrite(m_abre, LOW);  
  delay(d2);
  digitalWrite(m_cierra, HIGH);
  delay(d3);
  digitalWrite(m_cierra, LOW);
  delay(500);
}