/* ========================================================================== */
/* COMUNICACIÓN SERIE USB CON VISUAL BASIC (NS-GH - MÁQUINA PRINCIPAL)        */
/* ========================================================================== */

/* 
 * procesar_serial:
 * Lee de forma no bloqueante caracteres por USB hasta detectar fin de línea.
 * Ejecuta el comando recibido y retorna la tecla virtual asociada si aplica.
 */
char procesar_serial() {
  while (Serial.available() > 0) {
    char caracter_recibido = (char)Serial.read();

    if (caracter_recibido == '\n' || caracter_recibido == '\r') {
      buffer_recepcion_serie.trim();

      if (buffer_recepcion_serie.length() > 0) {
        char accion_ejecutada = interpretar_comando(buffer_recepcion_serie);
        buffer_recepcion_serie = "";
        if (accion_ejecutada != 0) {
          return accion_ejecutada;
        }
      }
    } else {
      if (buffer_recepcion_serie.length() < 64) {
        buffer_recepcion_serie += caracter_recibido;
      }
    }
  }
  return 0;
}

/* 
 * interpretar_comando:
 * Decodifica la instrucción enviada desde Visual Basic y ejecuta la acción.
 */
char interpretar_comando(String comando) {
  comando.toUpperCase();

  // 1. Identificación automática de máquina
  if (comando == "PING" || comando == "IDENT") {
    Serial.println("PONG:ID=MAIN:MODELO=NS-GH");
    return 0;
  }

  // 2. Control de arranque y parada de envasado
  if (comando == "INICIAR" || comando == "START") {
    solicitud_detener = false;
    envasando_activo = true;
    Serial.println("OK:INICIAR");
    return '1';
  }

  if (comando == "DETENER" || comando == "STOP") {
    solicitud_detener = true;
    envasando_activo = false;
    detener_maquina();
    Serial.println("OK:DETENIDO");
    return '*';
  }

  // 3. Acciones manuales de actuadores (JOG / Prueba)
  if (comando == "JOG_ARR" || comando == "ARRASTRAR") {
    jog_arrastre_manual();
    Serial.println("OK:JOG_ARR");
    return 0;
  }

  if (comando == "MOR_CIERRA") {
    mordazas_cerrar();
    Serial.println("OK:MOR_CIERRA");
    return 0;
  }

  if (comando == "MOR_ABRE") {
    mordazas_abrir();
    Serial.println("OK:MOR_ABRE");
    return 0;
  }

  if (comando == "CORTE" || comando == "ACT_PULSO") {
    pulso_actuador_corte();
    Serial.println("OK:CORTE");
    return 0;
  }

  // 4. Parámetros de sellado, arrastre y mordazas
  if (comando.startsWith("SET_SELLADO:") || comando.startsWith("SET_T_SELLADO:")) {
    int separador = comando.indexOf(':');
    int nuevo_tiempo = comando.substring(separador + 1).toInt();
    if (nuevo_tiempo >= 100 && nuevo_tiempo <= 9000) {
      tiempo_sellado = nuevo_tiempo;
      EEPROM.put(5, tiempo_sellado);
      Serial.println("OK:SET_SELLADO=" + String(tiempo_sellado));
    } else {
      Serial.println("ERR:TIEMPO_INVALIDO");
    }
    return 0;
  }

  if (comando.startsWith("SET_ARRASTRE:") || comando.startsWith("SET_T_ARRASTRE:")) {
    int separador = comando.indexOf(':');
    int nuevo_tiempo = comando.substring(separador + 1).toInt();
    if (nuevo_tiempo >= 50 && nuevo_tiempo <= 9000) {
      tiempo_arrastre = nuevo_tiempo;
      EEPROM.put(10, tiempo_arrastre);
      Serial.println("OK:SET_ARRASTRE=" + String(tiempo_arrastre));
    } else {
      Serial.println("ERR:TIEMPO_INVALIDO");
    }
    return 0;
  }

  if (comando.startsWith("SET_MOR_CIERRA:")) {
    int separador = comando.indexOf(':');
    int nuevo_tiempo = comando.substring(separador + 1).toInt();
    if (nuevo_tiempo >= 50 && nuevo_tiempo <= 5000) {
      tiempo_mordaza_cierra = nuevo_tiempo;
      EEPROM.put(35, tiempo_mordaza_cierra);
      Serial.println("OK:SET_MOR_CIERRA=" + String(tiempo_mordaza_cierra));
    } else {
      Serial.println("ERR:TIEMPO_INVALIDO");
    }
    return 0;
  }

  if (comando.startsWith("SET_MOR_ABRE:")) {
    int separador = comando.indexOf(':');
    int nuevo_tiempo = comando.substring(separador + 1).toInt();
    if (nuevo_tiempo >= 50 && nuevo_tiempo <= 5000) {
      tiempo_mordaza_abre = nuevo_tiempo;
      EEPROM.put(40, tiempo_mordaza_abre);
      Serial.println("OK:SET_MOR_ABRE=" + String(tiempo_mordaza_abre));
    } else {
      Serial.println("ERR:TIEMPO_INVALIDO");
    }
    return 0;
  }

  if (comando.startsWith("SET_FC_MOR:")) {
    int separador = comando.indexOf(':');
    int modo_fc = comando.substring(separador + 1).toInt();
    usar_fc_mordaza = (modo_fc == 1) ? 1 : 0;
    EEPROM.put(55, usar_fc_mordaza);
    Serial.println("OK:SET_FC_MOR=" + String(usar_fc_mordaza));
    return 0;
  }

  if (comando.startsWith("SET_TACA:")) {
    int separador = comando.indexOf(':');
    int modo_taca = comando.substring(separador + 1).toInt();
    usar_sensor_taca = (modo_taca == 1) ? 1 : 0;
    EEPROM.put(60, usar_sensor_taca);
    Serial.println("OK:SET_TACA=" + String(usar_sensor_taca));
    return 0;
  }

  if (comando.startsWith("SET_SECUENCIA:")) {
    int separador = comando.indexOf(':');
    int nueva_sec = comando.substring(separador + 1).toInt();
    secuencia_operacion = (nueva_sec == 1) ? 1 : 0;
    EEPROM.put(70, secuencia_operacion);
    Serial.println("OK:SET_SECUENCIA=" + String(secuencia_operacion));
    return 0;
  }

  if (comando.startsWith("SET_TIPO_MAQ:")) {
    int separador = comando.indexOf(':');
    int nuevo_tipo = comando.substring(separador + 1).toInt();
    tipo_maquina = (nuevo_tipo == 1) ? 1 : 0;
    EEPROM.put(90, tipo_maquina);
    Serial.println("OK:SET_TIPO_MAQ=" + String(tipo_maquina));
    return 0;
  }

  if (comando.startsWith("SET_CLAVE_LOCAL:")) {
    int separador = comando.indexOf(':');
    int nueva_clave = comando.substring(separador + 1).toInt();
    if (nueva_clave >= 0 && nueva_clave <= 999999) {
      clave_acceso = nueva_clave;
      EEPROM.put(0, clave_acceso);
      Serial.println("OK:SET_CLAVE_LOCAL=" + String(clave_acceso));
    } else {
      Serial.println("ERR:CLAVE_INVALIDA");
    }
    return 0;
  }

  // 5. Control de calentadores de sellado y temperaturas consigna
  if (comando == "CALENTAR:1" || comando == "CALENTAR_ON") {
    calefaccion_activa = true;
    for (int canal = 7; canal <= 10; canal++) {
      establecer_estado_calentador(canal, true);
    }
    Serial.println("OK:CALENTAR_ON");
    return 0;
  }

  if (comando == "CALENTAR:0" || comando == "CALENTAR_OFF") {
    calefaccion_activa = false;
    for (int canal = 7; canal <= 10; canal++) {
      establecer_estado_calentador(canal, false);
    }
    Serial.println("OK:CALENTAR_OFF");
    return 0;
  }

  if (comando.startsWith("SET_TEMP:")) {
    // Formato esperado: SET_TEMP:<ID_CANAL>:<TEMPERATURA> (Ej: SET_TEMP:7:160)
    int primer_sep = comando.indexOf(':');
    int segundo_sep = comando.indexOf(':', primer_sep + 1);
    if (segundo_sep > primer_sep) {
      int canal = comando.substring(primer_sep + 1, segundo_sep).toInt();
      int temp = comando.substring(segundo_sep + 1).toInt();
      if (canal >= 7 && canal <= 10 && temp >= 0 && temp <= 250) {
        establecer_temperatura_objetivo(canal, temp);

        if (canal == 7) { temp_consigna_sup_izq = temp; EEPROM.put(100, temp); }
        if (canal == 8) { temp_consigna_sup_der = temp; EEPROM.put(105, temp); }
        if (canal == 9) { temp_consigna_inf_ext = temp; EEPROM.put(110, temp); }
        if (canal == 10) { temp_consigna_inf_int = temp; EEPROM.put(115, temp); }

        Serial.println("OK:SET_TEMP:" + String(canal) + "=" + String(temp));
      } else {
        Serial.println("ERR:PARAMETROS_TEMP_INVALIDOS");
      }
    }
    return 0;
  }

  // 6. Reset de contador y restauración de fábrica
  if (comando == "RESET_CONT") {
    contador_bolsas = 0;
    EEPROM.put(65, contador_bolsas);
    Serial.println("OK:RESET_CONT");
    return 0;
  }

  if (comando == "RESET_VALORES" || comando == "FACTORY_RESET") {
    restablecer_valores_fabrica();
    Serial.println("OK:RESET_VALORES");
    return 0;
  }

  // 7. Solicitud de telemetría completa
  if (comando == "ESTADO" || comando == "STATUS" || comando == "GET_STATUS") {
    enviar_trama_estado();
    return 0;
  }

  Serial.println("ERR:COMANDO_DESCONOCIDO:" + comando);
  return 0;
}

/* 
 * enviar_trama_estado:
 * Envía el paquete estructurado con toda la telemetría actual a Visual Basic.
 */
void enviar_trama_estado() {
  Serial.print("ESTADO:");
  Serial.print(estado_maquina);
  Serial.print(";BOLSAS:");
  Serial.print(contador_bolsas);
  Serial.print(";BPM:");
  Serial.print(bolsas_por_minuto, 1);
  Serial.print(";T_SELL:");
  Serial.print(tiempo_sellado);
  Serial.print(";T_ARR:");
  Serial.print(tiempo_arrastre);
  Serial.print(";MOR_C:");
  Serial.print(tiempo_mordaza_cierra);
  Serial.print(";MOR_A:");
  Serial.print(tiempo_mordaza_abre);
  Serial.print(";FC_MOR:");
  Serial.print(usar_fc_mordaza);
  Serial.print(";TACA:");
  Serial.print(usar_sensor_taca);
  Serial.print(";SEC:");
  Serial.print(secuencia_operacion);
  Serial.print(";TIPO:");
  Serial.print(tipo_maquina);
  Serial.print(";CLAVE:");
  Serial.print(clave_acceso);
  Serial.print(";T1:");
  Serial.print(temp_actual_sup_izq);
  Serial.print(";T2:");
  Serial.print(temp_actual_sup_der);
  Serial.print(";T3:");
  Serial.print(temp_actual_inf_ext);
  Serial.print(";T4:");
  Serial.print(temp_actual_inf_int);
  Serial.print(";SET_T1:");
  Serial.print(temp_consigna_sup_izq);
  Serial.print(";SET_T2:");
  Serial.print(temp_consigna_sup_der);
  Serial.print(";SET_T3:");
  Serial.print(temp_consigna_inf_ext);
  Serial.print(";SET_T4:");
  Serial.print(temp_consigna_inf_int);
  Serial.print(";CAL:");
  Serial.print(calefaccion_activa ? "1" : "0");
  Serial.print(";TOLVAS_OK:");
  Serial.print(digitalRead(pin_sw_tolvas) == HIGH ? "1" : "0");
  Serial.println(";ID:MAIN");
}

/* 
 * enviar_telemetria_periodica:
 * Envía la trama a Visual Basic sin bloquear el bucle de control.
 */
void enviar_telemetria_periodica(String nuevo_estado, unsigned long intervalo_ms) {
  estado_maquina = nuevo_estado;
  unsigned long tiempo_actual = millis();
  if (tiempo_actual - tiempo_ultimo_envio_serie >= intervalo_ms) {
    tiempo_ultimo_envio_serie = tiempo_actual;
    enviar_trama_estado();
  }
}
