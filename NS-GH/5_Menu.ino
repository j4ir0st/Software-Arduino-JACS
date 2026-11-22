/* ========================================================================== */
/* PANTALLAS LCD Y MENÚ DE CONFIGURACIÓN LOCAL                                */
/* ========================================================================== */

/* 
 * mostrar_pantalla_reposo:
 * Despliega la información del estado principal en el LCD 20x4.
 */
void mostrar_pantalla_reposo() {
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("1)ENVASAR  3)CORTE");
  lcd.setCursor(0, 2);
  lcd.print("2)TEMP     4)CALEF:");
  lcd.print(calefaccion_activa ? "ON " : "OFF");
  lcd.setCursor(0, 3);
  lcd.print("5)ARRASTRE D)MENU");
}

/* 
 * pantalla_temperaturas:
 * Muestra en pantalla las 4 lecturas térmicas de mordazas.
 */
void pantalla_temperaturas() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("TEMPERATURAS");
  actualizar_todas_las_temperaturas();

  lcd.setCursor(0, 1);
  lcd.print("SUP.I:" + String(temp_actual_sup_izq) + "C");
  lcd.setCursor(10, 1);
  lcd.print("SUP.D:" + String(temp_actual_sup_der) + "C");

  lcd.setCursor(0, 2);
  lcd.print("INF.E:" + String(temp_actual_inf_ext) + "C");
  lcd.setCursor(10, 2);
  lcd.print("INF.I:" + String(temp_actual_inf_int) + "C");

  lcd.setCursor(0, 3);
  lcd.print("*)Volver    D)Set");

  while (true) {
    char tecla = teclado.getKey();
    char remoto = procesar_serial();
    if (tecla == '*' || remoto == '*') break;
    delay(50);
  }
  lcd.clear();
}

/* 
 * conmutar_calefaccion:
 * Alterna el encendido o apagado de las resistencias térmicas.
 */
void conmutar_calefaccion() {
  calefaccion_activa = !calefaccion_activa;
  for (int canal = 7; canal <= 10; canal++) {
    establecer_estado_calentador(canal, calefaccion_activa);
  }
  Serial.println(calefaccion_activa ? "OK:CALEFACCION_ON" : "OK:CALEFACCION_OFF");
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("CALEFACCION:");
  lcd.print(calefaccion_activa ? " ACTIVA" : " APAGADA");
  delay(1200);
  lcd.clear();
}

/* 
 * menu_principal_opciones:
 * Menú local protegido para ajuste de tiempos y sensores.
 */
void menu_principal_opciones() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("AJUSTES DE TIEMPO");
  lcd.setCursor(0, 1);
  lcd.print("1)SELLADO (" + String(tiempo_sellado) + "ms)");
  lcd.setCursor(0, 2);
  lcd.print("2)ARRASTRE (" + String(tiempo_arrastre) + "ms)");
  lcd.setCursor(0, 3);
  lcd.print("3)TACA (" + String(usar_sensor_taca == 1 ? "ON" : "OFF") + ") *)Salir");

  while (true) {
    char tecla = teclado.getKey();
    char remoto = procesar_serial();
    if (tecla == '*' || remoto == '*') break;

    if (tecla == '1') {
      int nuevo_sell = ingresar_entero("TIEMPO SELLADO", 100, 9000, "ms");
      if (nuevo_sell > 0) {
        tiempo_sellado = nuevo_sell;
        EEPROM.put(5, tiempo_sellado);
      }
      break;
    }
    if (tecla == '2') {
      int nuevo_arr = ingresar_entero("TIEMPO ARRASTRE", 50, 9000, "ms");
      if (nuevo_arr > 0) {
        tiempo_arrastre = nuevo_arr;
        EEPROM.put(10, tiempo_arrastre);
      }
      break;
    }
    if (tecla == '3') {
      usar_sensor_taca = (usar_sensor_taca == 1) ? 0 : 1;
      EEPROM.put(60, usar_sensor_taca);
      break;
    }
    delay(50);
  }
  lcd.clear();
}
