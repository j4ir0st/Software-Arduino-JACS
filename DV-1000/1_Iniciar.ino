/* ========================================================================== */
/* PROCESO PRINCIPAL DE DOSIFICACIÓN Y CONTROL DE PESO                        */
/* ========================================================================== */

/* 
 * iniciar:
 * Ejecuta el ciclo completo de dosificación automática o manual:
 * 1. Activa vibración gruesa hasta alcanzar (peso_objetivo - vibracion_fina).
 * 2. Activa vibración fina hasta alcanzar (peso_objetivo - inercia).
 * 3. Ejecuta autocorrección si está habilitada.
 * 4. Descarga el material en modo automático o espera confirmación en modo manual.
 * Permite interrupción instantánea mediante tecla '*', parada de emergencia o comando USB 'STOP'.
 */
void iniciar(){
  solicitud_detener_remoto = false;

  // Verificación previa: Si la parada de emergencia está activada, no arranca
  if (digitalRead(PE) == 0) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PARADA DE EMERGENCIA");
    lcd.setCursor(6, 2);
    lcd.print("ACTIVADA");
    while (digitalRead(PE) == 0) {
      delay(100);
    }
    return;
  }

  /* Limpieza y mensaje de inicio en pantalla LCD */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(4, 3);
  lcd.print("Iniciando...");
  delay(500);

  listo = false;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 3);
  lcd.print("*)Detener");
  lcd.setCursor(0, 1);
  lcd.print("PESO:");
  
  peso_vg = s_peso - v_fina;    // Punto de corte de vibración gruesa
  peso_vf = s_peso - inercia;   // Punto de corte de vibración fina
  
  /* Bucle activo de dosificación */
  while(regresar() == false){
    peso = print_peso();

    // Etapa 1: Dosificación gruesa (velocidad rápida)
    if(peso <= peso_vg){
      estado_dosificador = "DOSIF_GRUESA";
      digitalWrite(gruesa, HIGH);
      digitalWrite(fina, LOW);
    }
    // Etapa 2: Dosificación fina (ajuste de precisión)
    else if(peso < peso_vf && peso >= peso_vg){
      estado_dosificador = "DOSIF_FINA";
      digitalWrite(gruesa, LOW);
      digitalWrite(fina, HIGH);
    }
    // Etapa 3: Peso alcanzado, corte de vibradores y descarga
    else{
      digitalWrite(gruesa, LOW);
      digitalWrite(fina, LOW);
      estado_dosificador = "PESO_LISTO";

      if(i_modo == 1){
        // Modo Automático: Autocorrección y descarga programada
        auto_corrector();
        delay(delay_aut);
        estado_dosificador = "DESCARGANDO";
        enviar_trama_estado();
        descargar();
        contador++;
        var_cont++;
        EEPROM.put(140, contador);
        enviar_evento_descarga_iot();
        enviar_telemetria_periodica("ESPERA", 0);
      }
      else if(i_modo == 2){
        // Modo Manual: Espera confirmación por pulsador, tecla '#' o comando serie
        auto_corrector();
        estado_dosificador = "ESPERA_DESCARGA";
        while(1){
          TECLA = teclado.getKey();
          char comando_serie = procesar_serial();
          char comando_iot = procesar_serial_iot();
          peso = print_peso();
          enviar_telemetria_periodica("ESPERA_DESCARGA", 200);
          enviar_telemetria_iot_periodica("ESPERA_DESCARGA", 1000);

          if(regresar())
            return;

          /* Descarga activada por tecla '#' o comando USB / IoT (sin sensor mecánico de descarga) */
          if(TECLA == '#' || comando_serie == '#' || comando_iot == '#'){
            estado_dosificador = "DESCARGANDO";
            enviar_trama_estado();
            descargar();
            contador++;
            var_cont++;
            EEPROM.put(140, contador);
            enviar_evento_descarga_iot();
            enviar_telemetria_periodica("ESPERA", 0);
            break;
          }
        }
      }
    }
    
    // Envía telemetría en tiempo real a Visual Basic cada 100 ms durante el ciclo
    enviar_telemetria_periodica(estado_dosificador, 100);
    // Envía telemetría en tiempo real a la nube (Serial1) cada 500 ms durante el ciclo
    enviar_telemetria_iot_periodica(estado_dosificador, 500);
  }
}

/* 
 * auto_corrector:
 * Realiza pulsos breves de vibración si el peso final quedó por debajo del objetivo.
 */
void auto_corrector(){
  if (ac_modo == 1){
    peso = print_peso();
    while(peso < s_peso){
      if (regresar()) return; // Permite cancelar la autocorrección si se presiona detener
      delay(t_ac1);
      digitalWrite(gruesa, HIGH);
      digitalWrite(fina, HIGH);
      delay(t_ac2);
      digitalWrite(gruesa, LOW);
      digitalWrite(fina, LOW);
      delay(t_ac3);
      peso = print_peso();
      enviar_telemetria_periodica("AUTOCORRECCION", 100);
    }
  }
}

/* 
 * regresar:
 * Evalúa si el usuario local, Visual Basic o la parada de emergencia ordenan detener el proceso.
 * Si se activa la Parada de Emergencia (PE):
 * 1. Apaga inmediatamente todos los actuadores.
 * 2. Ejecuta la descarga de vaciado de tolva UNA SOLA VEZ.
 * 3. Mantiene detenida la máquina y espera a que el botón PE cambie de estado (se libere).
 * 4. Retorna true para finalizar el ciclo y volver al menú principal en estado detenido.
 */
boolean regresar(){
  // 1. Verificación física de Parada de Emergencia (PE) durante funcionamiento
  if (digitalRead(PE) == 0) {
    digitalWrite(fina, LOW);
    digitalWrite(gruesa, LOW);
    estado_dosificador = "DETENIDO";

    // Descarga de seguridad ejecutada UNA SOLA VEZ
    descargar();

    // Pantalla de alerta: espera a que se desenclave / libere la parada de emergencia
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PARADA DE EMERGENCIA");
    lcd.setCursor(6, 2);
    lcd.print("ACTIVADA");

    while (digitalRead(PE) == 0) {
      delay(100);
    }

    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("JACS MAQUINAS");
    lcd.setCursor(4, 2);
    lcd.print("EMERGENCIA OK");
    delay(1000);

    EEPROM.put(140, contador);
    Serial.println("OK:DETENIDO");
    enviar_trama_estado();

    return true; // Aborta inmediatamente el proceso y regresa al menú
  }

  // 2. Verificación del teclado físico
  TECLA = teclado.getKey();

  // 3. Verificación de comandos serie USB e IoT (Nube)
  char comando_serie = procesar_serial();
  char comando_iot = procesar_serial_iot();
  if (comando_serie == '*' || comando_iot == '*' || solicitud_detener_remoto) {
    TECLA = '*';
    solicitud_detener_remoto = false;
  }

  switch(TECLA){
    case '*':        
      digitalWrite(fina, LOW);
      digitalWrite(gruesa, LOW);   
      digitalWrite(m_abre, LOW);
      digitalWrite(m_cierra, LOW);
      estado_dosificador = "DETENIDO";
      
      lcd.clear();
      lcd.print("   JACS MAQUINAS");
      lcd.setCursor(3, 3);
      lcd.print("Finalizando...");  
      delay(1500); 
      EEPROM.put(140, contador);
      Serial.println("OK:DETENIDO");
      enviar_trama_estado();
      delay(500);      
      return true;

    case 'C':
      auto_inercia();
      return false;

    default:
      return false;
  }
}

/* 
 * auto_inercia:
 * Ajusta automáticamente el valor de inercia basado en el desfase de peso obtenido.
 */
boolean auto_inercia(){ 
  Serial.println("OK:AUTO_INERCIA");   
  inercia = inercia + get_peso() - s_peso;
  EEPROM.put(40, inercia);
  lcd.setCursor(19, 0);
  lcd.print("C");
  delay(1000);
  lcd.setCursor(19, 0);
  lcd.print(" ");
  delay(1000);    
  return true;
}
