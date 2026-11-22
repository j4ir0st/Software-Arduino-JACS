/* ========================================================================== */
/* RUTINA Y CICLO PRINCIPAL DE ENVASADO CONTINUO                              */
/* ========================================================================== */

/* 
 * iniciar_envasado:
 * Prepara e inicia la secuencia automática continua de producción.
 */
void iniciar_envasado() {
  solicitud_detener = false;
  envasando_activo = true;
  tiempo_ciclo_inicio = millis();

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("ENVASANDO...");
  lcd.setCursor(0, 3);
  lcd.print("*)Detener");

  Serial.println("OK:ENVASADO_INICIADO");
}

/* 
 * ciclo_envasado_continuo:
 * Ejecuta un ciclo de conformado, sellado, dosificación y arrastre de bolsa:
 * 1. Verifica parada de emergencia o comando de detención.
 * 2. Cierra mordazas (sellado horizontal y corte).
 * 3. Mantiene presión durante tiempo_sellado.
 * 4. Abre mordazas.
 * 5. Si hay tolvas balanza conectadas, espera confirmación de descarga.
 * 6. Arrastra película de empaque (por tiempo fijo o sensor de taco óptico).
 * 7. Incrementa contador y calcula velocidad (Bolsas Por Minuto).
 */
void ciclo_envasado_continuo() {
  // Comprobación inicial de parada
  if (verificar_parada()) {
    detener_maquina();
    return;
  }

  tiempo_ciclo_inicio = millis();

  // Paso 1: Cierre de mordazas de sellado
  estado_maquina = "SELLANDO";
  enviar_telemetria_periodica(estado_maquina, 100);
  mordazas_cerrar();
  if (verificar_parada()) { detener_maquina(); return; }

  // Paso 2: Tiempo de prensado y sellado térmico
  delay(tiempo_sellado);
  if (verificar_parada()) { detener_maquina(); return; }

  // Paso 3: Apertura de mordazas de sellado
  mordazas_abrir();
  if (verificar_parada()) { detener_maquina(); return; }

  // Paso 4: Espera de tolva dosificadora (si la sincronización física está activa)
  estado_maquina = "ESPERA_TOLVAS";
  enviar_telemetria_periodica(estado_maquina, 100);
  if (digitalRead(pin_sw_tolvas) == HIGH) {
    // Si la entrada física está activa, esperamos el pulso de descarga completada
    unsigned long tiempo_espera_tolva = millis();
    while (digitalRead(pin_sw_tolvas) == HIGH) {
      if (verificar_parada()) { detener_maquina(); return; }
      if (millis() - tiempo_espera_tolva > 5000) break; // Timeout de seguridad 5 seg
      delay(50);
    }
  }

  // Paso 5: Arrastre de película plástica
  estado_maquina = "ARRASTRANDO";
  enviar_telemetria_periodica(estado_maquina, 100);
  if (usar_sensor_taca == 1) {
    arrastrar_con_taca();
  } else {
    arrastrar_pelicula();
  }
  if (verificar_parada()) { detener_maquina(); return; }

  // Paso 6: Conteo y cálculo de rendimiento
  contador_bolsas++;
  EEPROM.put(65, contador_bolsas);
  tiempo_ciclo_fin = millis();
  double duracion_ciclo_seg = (tiempo_ciclo_fin - tiempo_ciclo_inicio) / 1000.0;
  if (duracion_ciclo_seg > 0.1) {
    bolsas_por_minuto = (float)(60.0 / duracion_ciclo_seg);
  }

  // Actualización de datos en pantalla LCD
  lcd.setCursor(0, 1);
  lcd.print("BPM:" + String(bolsas_por_minuto, 1) + "   ");
  lcd.setCursor(10, 1);
  lcd.print("N:" + String(contador_bolsas));

  // Envío de telemetría a Visual Basic
  enviar_trama_estado();
}

/* 
 * verificar_parada:
 * Evalúa si se presionó la tecla '*', el botón físico de emergencia o el comando USB 'STOP'.
 */
boolean verificar_parada() {
  if (leer_parada_emergencia() == LOW) return true;
  if (solicitud_detener) return true;

  char tecla_presionada = teclado.getKey();
  if (tecla_presionada == '*') return true;

  char comando = procesar_serial();
  if (comando == '*') return true;

  return false;
}

/* 
 * detener_maquina:
 * Desactiva inmediatamente todas las salidas de relé y regresa a modo reposo.
 */
void detener_maquina() {
  envasando_activo = false;
  solicitud_detener = false;

  // Apagar actuadores por seguridad
  digitalWrite(pin_mordazas, LOW);
  digitalWrite(pin_arrastre, LOW);
  digitalWrite(pin_actuador, LOW);
  digitalWrite(pin_aux1, LOW);

  estado_maquina = "DETENIDO";
  Serial.println("OK:MAQUINA_DETENIDA");

  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(4, 2);
  lcd.print("DETENIENDO...");
  delay(800);
}
