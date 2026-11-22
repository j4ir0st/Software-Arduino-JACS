/* ========================================================================== */
/* COMUNICACIÓN SERIE USB CON VISUAL BASIC (DV-1000)                          */
/* Protocolo bidireccional no bloqueante para control de múltiples tolvas     */
/* ========================================================================== */

/* 
 * procesar_serial:
 * Lee de forma no bloqueante los caracteres que llegan por el puerto serie USB.
 * Acumula en el búfer hasta encontrar un delimitador de fin de línea ('\n' o '\r').
 * Retorna un carácter de tecla virtual si el comando corresponde a una acción
 * directa del menú ('1', '*', '4', '#', 'D'), o 0 si fue un comando interno de configuración.
 */
char procesar_serial() {
  while (Serial.available() > 0) {
    char caracter_recibido = (char)Serial.read();

    // Si encontramos salto de línea, procesamos el comando completo
    if (caracter_recibido == '\n' || caracter_recibido == '\r') {
      buffer_recepcion_serie.trim(); // Elimina espacios en blanco o retornos sobrantes
      
      if (buffer_recepcion_serie.length() > 0) {
        char accion_ejecutada = interpretar_comando(buffer_recepcion_serie);
        buffer_recepcion_serie = ""; // Limpia el búfer para el siguiente comando
        if (accion_ejecutada != 0) {
          return accion_ejecutada;
        }
      }
    } else {
      // Acumula el carácter recibido en el búfer si no supera la capacidad máxima
      if (buffer_recepcion_serie.length() < 64) {
        buffer_recepcion_serie += caracter_recibido;
      }
    }
  }
  return 0; // No hay acción de tecla pendiente
}

/* 
 * interpretar_comando:
 * Analiza la cadena recibida y ejecuta la función correspondiente.
 * Responde a Visual Basic con tramas estandarizadas 'OK:...' o 'ERR:...'.
 */
char interpretar_comando(String comando) {
  conexion_pc_activa = true; // Activa comunicación con PC al recibir comandos válidos
  comando.toUpperCase(); // Normaliza a mayúsculas para evitar discrepancias

  // 1. Comando INICIAR (equivalente a presionar '1')
  if (comando == "INICIAR" || comando == "START") {
    Serial.println("OK:INICIAR");
    return '1';
  }

  // 2. Comando DETENER (equivalente a presionar '*')
  if (comando == "DETENER" || comando == "STOP") {
    solicitud_detener_remoto = true;
    Serial.println("OK:DETENIDO");
    return '*';
  }

  // 3. Comando TARA (equivalente a presionar '4')
  if (comando == "TARA" || comando == "TARE") {
    Serial.println("OK:TARA");
    return '4';
  }

  // 4. Comando DESCARGAR (equivalente a presionar '#')
  if (comando == "DESCARGAR" || comando == "DESC" || comando == "DISCH") {
    Serial.println("OK:DESCARGAR");
    return '#';
  }

  // 5. Comando MENU (equivalente a presionar 'D')
  if (comando == "MENU") {
    Serial.println("OK:MENU");
    return 'D';
  }

  // 6. Comando PING: Para descubrimiento e identificación de tolvas desde Visual Basic
  if (comando == "PING" || comando == "IDENT") {
    Serial.println("PONG:ID=" + String(id_dosificador) + ":MODELO=DV1000");
    return 0;
  }

  // 7. Comando ESTADO: Consulta bajo demanda del estado actual
  if (comando == "ESTADO" || comando == "STATUS" || comando == "GET_STATUS") {
    enviar_trama_estado();
    return 0;
  }

  // 8. Comando para configurar ID del dosificador (Ejemplo: ID:1 o SETID:2)
  if (comando.startsWith("ID:") || comando.startsWith("SETID:")) {
    int separador = comando.indexOf(':');
    int nuevo_id = comando.substring(separador + 1).toInt();
    if (nuevo_id > 0 && nuevo_id <= 99) {
      id_dosificador = nuevo_id;
      EEPROM.put(190, id_dosificador);
      Serial.println("OK:ID=" + String(id_dosificador));
    } else {
      Serial.println("ERR:ID_INVALIDO");
    }
    return 0;
  }

  // 9. Comando para asignar Peso Objetivo (Ejemplo: PESO:500 o SETP:500)
  if (comando.startsWith("PESO:") || comando.startsWith("SETP:")) {
    int separador = comando.indexOf(':');
    int nuevo_peso = comando.substring(separador + 1).toInt();
    if (nuevo_peso >= peso_min && (peso_max == 0 || nuevo_peso <= peso_max)) {
      s_peso = nuevo_peso;
      EEPROM.put(20, s_peso);
      Serial.println("OK:PESO=" + String(s_peso));
      // Actualiza en pantalla LCD si está en pantalla principal
      lcd.setCursor(0, 2);
      lcd.print("2)PESO(" + String(s_peso) + "gr)   ");
    } else {
      Serial.println("ERR:PESO_FUERA_DE_RANGO");
    }
    return 0;
  }

  // 10. Comando para asignar Vibración Fina (Ejemplo: VFINA:25 o SETVF:25)
  if (comando.startsWith("VFINA:") || comando.startsWith("SETVF:")) {
    int separador = comando.indexOf(':');
    int nueva_vf = comando.substring(separador + 1).toInt();
    if (nueva_vf >= 0 && nueva_vf <= 1000) {
      v_fina = nueva_vf;
      EEPROM.put(80, v_fina);
      Serial.println("OK:VFINA=" + String(v_fina));
      // Actualiza en pantalla LCD si está en pantalla principal
      lcd.setCursor(0, 3);
      lcd.print("3)VF(" + String(v_fina) + "gr)   ");
    } else {
      Serial.println("ERR:VFINA_INVALIDA");
    }
    return 0;
  }

  // 11. Comando para asignar Inercia (Ejemplo: INERCIA:5 o SETINER:5)
  if (comando.startsWith("INERCIA:") || comando.startsWith("SETINER:")) {
    int separador = comando.indexOf(':');
    int nueva_inercia = comando.substring(separador + 1).toInt();
    inercia = nueva_inercia;
    EEPROM.put(40, inercia);
    Serial.println("OK:INERCIA=" + String(inercia));
    return 0;
  }

  // 12. Comando para configurar Tiempo de Descarga (Ejemplo: TDESC:2000 o SET_DESC:2000)
  if (comando.startsWith("TDESC:") || comando.startsWith("SET_DESC:")) {
    int separador = comando.indexOf(':');
    int nuevo_tdesc = comando.substring(separador + 1).toInt();
    if (nuevo_tdesc >= 100 && nuevo_tdesc <= 30000) {
      tiempo_descarga = nuevo_tdesc;
      d2 = tiempo_descarga;
      EEPROM.put(60, tiempo_descarga);
      Serial.println("OK:TDESC=" + String(tiempo_descarga));
    } else {
      Serial.println("ERR:TDESC_INVALIDO");
    }
    return 0;
  }

  // Comando no reconocido
  Serial.println("ERR:COMANDO_DESCONOCIDO:" + comando);
  return 0;
}

/* 
 * enviar_trama_estado:
 * Envía una cadena estructurada con todos los parámetros actuales a Visual Basic.
 */
void enviar_trama_estado() {
  Serial.print("ESTADO:");
  Serial.print(estado_dosificador);
  Serial.print(";PESO:");
  Serial.print(roundf(peso));
  Serial.print(";OBJETIVO:");
  Serial.print(s_peso);
  Serial.print(";VFINA:");
  Serial.print(v_fina);
  Serial.print(";INERCIA:");
  Serial.print(inercia);
  Serial.print(";TDESC:");
  Serial.print(tiempo_descarga);
  Serial.print(";CONTADOR:");
  Serial.print(contador);
  Serial.print(";ID:");
  Serial.println(id_dosificador);
}

/* 
 * enviar_telemetria_periodica:
 * Envía telemetría a Visual Basic cada cierto intervalo de tiempo en milisegundos,
 * sin utilizar delay(), garantizando que la lectura y control continúen sin pausas.
 */
void enviar_telemetria_periodica(String nuevo_estado, unsigned long intervalo_ms) {
  estado_dosificador = nuevo_estado;
  
  // Si la PC (.NET) aún no ha establecido conexión, no saturamos el puerto serie
  if (!conexion_pc_activa) return;

  unsigned long tiempo_actual = millis();
  if (tiempo_actual - tiempo_ultimo_envio_serie >= intervalo_ms) {
    tiempo_ultimo_envio_serie = tiempo_actual;
    enviar_trama_estado();
  }
}
