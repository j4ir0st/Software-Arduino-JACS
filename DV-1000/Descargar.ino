/* ========================================================================== */
/* RUTINA DE DESCARGA: CONTROL DE PISTÓN NEUMÁTICO POR TIEMPO                */
/* ========================================================================== */

/* 
 * descargar:
 * Abre la compuerta del pistón neumático durante tiempo_descarga milisegundos (default 2000 ms),
 * y ejecuta el ciclo de cierre seguro sin depender de sensores mecánicos.
 */
void descargar(){
  estado = 0;
  // 1. Activar apertura de compuerta neumática
  digitalWrite(m_abre, HIGH);
  digitalWrite(m_cierra, LOW);

  // 2. Tiempo de descarga del material (temporizado, default 2000 ms)
  delay(tiempo_descarga);

  // 3. Activar cierre de compuerta neumática
  digitalWrite(m_abre, LOW);
  digitalWrite(m_cierra, HIGH);
  delay(d3 > 0 ? d3 : 400); // Tiempo para completar el cierre
  digitalWrite(m_cierra, LOW);
  delay(200);
}
