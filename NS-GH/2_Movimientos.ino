/* ========================================================================== */
/* CONTROL DE MOVIMIENTOS: MORDAZAS, ARRASTRE Y CORTE                         */
/* ========================================================================== */

/* 
 * mordazas_cerrar:
 * Activa la salida de relé de las mordazas durante el tiempo configurado o hasta fin de carrera.
 */
void mordazas_cerrar() {
  digitalWrite(pin_mordazas, HIGH);
  delay(tiempo_mordaza_cierra);

  if (usar_fc_mordaza == 1) {
    unsigned long tiempo_inicio = millis();
    while (leer_fc_mordazas() == LOW) {
      if (verificar_parada()) break;
      if (millis() - tiempo_inicio > 3000) break; // Timeout de 3 segundos
      delay(10);
    }
  }
}

/* 
 * mordazas_abrir:
 * Desactiva el relé de mordazas y espera el retorno completo del pistón.
 */
void mordazas_abrir() {
  digitalWrite(pin_mordazas, LOW);
  delay(tiempo_mordaza_abre);
}

/* 
 * arrastrar_pelicula:
 * Enciende el motor de arrastre durante tiempo_arrastre milisegundos.
 */
void arrastrar_pelicula() {
  digitalWrite(pin_arrastre, HIGH);
  delay(tiempo_arrastre);
  digitalWrite(pin_arrastre, LOW);
}

/* 
 * arrastrar_con_taca:
 * Avanza película hasta que la fotocélula detecte la marca de taco de corte.
 */
void arrastrar_con_taca() {
  digitalWrite(pin_arrastre, HIGH);
  unsigned long tiempo_inicio = millis();

  // Avanza un retardo mínimo inicial para superar la marca previa
  delay(100);

  // Busca el flanco del sensor óptico de taco
  while (leer_sensor_taca() == LOW) {
    if (verificar_parada()) break;
    // Si tarda más de 2 segundos sin encontrar la marca, detiene por seguridad
    if (millis() - tiempo_inicio > 2000) {
      Serial.println("ERR:FALLO_SENSOR_TACA");
      break;
    }
    delay(2);
  }

  digitalWrite(pin_arrastre, LOW);
}

/* 
 * jog_arrastre_manual:
 * Avanza película por comando directo o pulsador externo manual.
 */
void jog_arrastre_manual() {
  digitalWrite(pin_arrastre, HIGH);
  delay(tiempo_arrastre);
  digitalWrite(pin_arrastre, LOW);
  Serial.println("OK:JOG_ARRASTRE_EJECUTADO");
}

/* 
 * pulso_actuador_corte:
 * Envía un pulso de corte al pistón de cuchilla o fechador auxiliar.
 */
void pulso_actuador_corte() {
  digitalWrite(pin_actuador, HIGH);
  delay(200);
  digitalWrite(pin_actuador, LOW);
}
