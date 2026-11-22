/* ========================================================================== */
/* FUNCIONES DE ENTRADA DE DATOS Y PRUEBAS MANUALES                           */
/* ========================================================================== */

/* 
 * ingresar_entero:
 * Permite capturar un número entero en el display LCD mediante el teclado matricial.
 */
int ingresar_entero(String titulo, int val_minimo, int val_maximo, String unidad) {
  String valor_texto = "";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(titulo);
  lcd.setCursor(0, 1);
  lcd.print("Unidad: " + unidad);
  lcd.setCursor(0, 3);
  lcd.print("*)Canc  D)Aceptar");

  while (true) {
    char tecla = teclado.getKey();
    char remoto = procesar_serial();
    if (tecla == '*' || remoto == '*') return -1;

    if (tecla >= '0' && tecla <= '9') {
      if (valor_texto.length() < 5) {
        valor_texto += tecla;
        lcd.setCursor(0, 2);
        lcd.print(valor_texto + " " + unidad + "    ");
      }
    }

    if (tecla == 'D' && valor_texto.length() > 0) {
      int valor_numerico = valor_texto.toInt();
      if (valor_numerico >= val_minimo && valor_numerico <= val_maximo) {
        return valor_numerico;
      } else {
        lcd.clear();
        lcd.print("VALOR FUERA DE RANGO");
        delay(1200);
        return -1;
      }
    }
    delay(30);
  }
}

/* 
 * probar_actuador:
 * Ejecuta una prueba manual del pistón de corte o auxiliar.
 */
void probar_actuador() {
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("PROBANDO CORTE");
  pulso_actuador_corte();
  delay(1000);
  lcd.clear();
}
