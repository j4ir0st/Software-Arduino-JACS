/* ========================================================================== */
/* LECTURA Y FILTRADO DE SENSORES Y ENTRADAS DIGITALES                        */
/* ========================================================================== */

/* 
 * leer_parada_emergencia:
 * Retorna LOW si el pulsador tipo hongo de emergencia está presionado.
 */
int leer_parada_emergencia() {
  return digitalRead(pin_parada_emergencia);
}

/* 
 * leer_fc_mordazas:
 * Retorna HIGH cuando las mordazas han alcanzado la posición de apertura completa.
 */
int leer_fc_mordazas() {
  return digitalRead(pin_fc_mordazas);
}

/* 
 * leer_sensor_taca:
 * Lee el estado del sensor óptico de fotomarca de impresión.
 */
int leer_sensor_taca() {
  return digitalRead(pin_sensor_taca);
}

/* 
 * leer_arrastre_manual:
 * Lee el pulsador físico exterior de avance manual de película.
 */
int leer_arrastre_manual() {
  return digitalRead(pin_arrastre_manual);
}

/* 
 * leer_sw_tolvas:
 * Lee la señal de sincronización enviada por las tolvas dosificadoras.
 */
int leer_sw_tolvas() {
  return digitalRead(pin_sw_tolvas);
}
