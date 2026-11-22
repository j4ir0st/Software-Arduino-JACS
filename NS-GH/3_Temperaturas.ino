/* ========================================================================== */
/* GESTIÓN DE TEMPERATURAS MEDIANTE RS-485 MODBUS (PIRÓMETROS)                */
/* ========================================================================== */

/* Callback de pre-transmisión RS-485: habilita emisor MAX485 */
void pre_transmision_modbus() {
  digitalWrite(PIN_MAX485_RE_NEG, 1);
  digitalWrite(PIN_MAX485_DE, 1);
}

/* Callback de post-transmisión RS-485: regresa a modo recepción */
void post_transmision_modbus() {
  digitalWrite(PIN_MAX485_RE_NEG, 0);
  digitalWrite(PIN_MAX485_DE, 0);
}

/* 
 * leer_temperatura_actual:
 * Lee por Modbus RTU el registro 0x41 del pirómetro con ID especificado.
 */
int leer_temperatura_actual(int id_pirómetro) {
  int temp_leida = 0;
  nodo_modbus.begin(id_pirómetro, Serial1);
  nodo_modbus.clearResponseBuffer();
  delay(5);
  uint8_t resultado = nodo_modbus.readHoldingRegisters(0x41, 1);
  if (resultado == nodo_modbus.ku8MBSuccess) {
    temp_leida = nodo_modbus.getResponseBuffer(0);
    if (temp_leida >= 9999 || temp_leida < 0) {
      temp_leida = 0;
    }
  }
  nodo_modbus.clearResponseBuffer();
  return temp_leida;
}

/* 
 * leer_temperatura_consigna:
 * Consulta la temperatura fijada como objetivo (SetPoint) en el controlador.
 */
int leer_temperatura_consigna(int id_pirómetro) {
  int setpoint = 0;
  nodo_modbus.begin(id_pirómetro, Serial1);
  nodo_modbus.clearResponseBuffer();
  delay(5);
  uint8_t resultado = nodo_modbus.readHoldingRegisters(0x00, 1);
  if (resultado == nodo_modbus.ku8MBSuccess) {
    setpoint = nodo_modbus.getResponseBuffer(0);
  }
  nodo_modbus.clearResponseBuffer();
  return setpoint;
}

/* 
 * establecer_temperatura_objetivo:
 * Escribe el SetPoint de temperatura deseado en el pirómetro Modbus.
 */
void establecer_temperatura_objetivo(int id_pirómetro, int nueva_temperatura) {
  nodo_modbus.begin(id_pirómetro, Serial1);
  delay(5);
  nodo_modbus.writeSingleRegister(0x00, nueva_temperatura);
}

/* 
 * establecer_estado_calentador:
 * Enciende o apaga la salida de calefacción del pirómetro (registro 0x43 o comando RUN/STOP).
 */
void establecer_estado_calentador(int id_pirómetro, boolean encender) {
  nodo_modbus.begin(id_pirómetro, Serial1);
  delay(5);
  nodo_modbus.writeSingleRegister(0x43, encender ? 1 : 0);
}

/* 
 * actualizar_todas_las_temperaturas:
 * Actualiza en memoria las temperaturas de los cuatro pirómetros de mordazas.
 */
void actualizar_todas_las_temperaturas() {
  temp_actual_sup_izq = leer_temperatura_actual(7);
  temp_actual_sup_der = leer_temperatura_actual(8);
  temp_actual_inf_ext = leer_temperatura_actual(9);
  temp_actual_inf_int = leer_temperatura_actual(10);
}
