#include "Header.h"

/* ========================================================================== */
/* CONFIGURACIÓN INICIAL DEL ARDUINO PRINCIPAL (SETUP)                        */
/* ========================================================================== */
void setup() {
  /* Configuración de pines de salidas de potencia y actuadores */
  pinMode(PIN_MAX485_RE_NEG, OUTPUT);
  pinMode(PIN_MAX485_DE, OUTPUT);  
  pinMode(pin_mordazas, OUTPUT); 
  pinMode(pin_actuador, OUTPUT);
  pinMode(pin_arrastre, OUTPUT);
  pinMode(pin_aux1, OUTPUT);
  pinMode(pin_aux2, OUTPUT);
  pinMode(pin_aux3, OUTPUT);

  /* Apagar todas las salidas al iniciar por seguridad */
  digitalWrite(pin_mordazas, LOW);
  digitalWrite(pin_actuador, LOW);
  digitalWrite(pin_arrastre, LOW);
  digitalWrite(pin_aux1, LOW);
  digitalWrite(pin_aux2, LOW);
  digitalWrite(pin_aux3, LOW);

  /* Configuración de pines de entradas digitales con resistencias pull-up */
  pinMode(pin_sw_tolvas, INPUT);
  pinMode(pin_fc_mordazas, INPUT);
  pinMode(pin_fc_aux, INPUT);
  pinMode(pin_parada_emergencia, INPUT);
  pinMode(pin_sensor_taca, INPUT);
  pinMode(pin_arrastre_manual, INPUT);

  /* Inicialización de comunicación serie USB hacia el PC (Visual Basic) */
  Serial.begin(9600);

  /* Inicialización de pantalla LCD I2C */
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, barra_progreso);
  lcd.createChar(1, flecha_sube);
  lcd.createChar(2, flecha_baja);

  /* Mensaje de bienvenida en pantalla LCD */
  lcd.setCursor(3, 1);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(4, 2);
  lcd.print("ENVASADORA NS-GH");
  delay(1500);

  /* Carga de parámetros almacenados en memoria EEPROM */
  cargar_valores();

  /* Inicialización del bus RS-485 Modbus para pirómetros de temperatura */
  digitalWrite(PIN_MAX485_RE_NEG, 0);
  digitalWrite(PIN_MAX485_DE, 0);
  Serial1.begin(9600);             
  nodo_modbus.begin(7, Serial1); 
  nodo_modbus.preTransmission(pre_transmision_modbus);
  nodo_modbus.postTransmission(post_transmision_modbus);

  /* Apagar resistencias de sellado en inicio por seguridad */
  for (int canal = 7; canal <= 10; canal++) {
    establecer_estado_calentador(canal, false);
  }

  lcd.clear();
  Serial.println("OK:SISTEMA_LISTO:NS-GH");
}

/* ========================================================================== */
/* BUCLE PRINCIPAL DE CONTROL (LOOP)                                          */
/* ========================================================================== */
void loop() {
  /* Si está activo el ciclo continuo de envasado, ejecuta la rutina de producción */
  if (envasando_activo) {
    ciclo_envasado_continuo();
  } else {
    /* Pantalla principal de reposo */
    mostrar_pantalla_reposo();
    estado_maquina = "ESPERA";

    /* Supervisa eventos de teclado físico, comandos USB o pulsadores externos */
    char accion = supervisar_entradas();
    switch (accion) {
      case '1': // Iniciar envasado
        iniciar_envasado();
        break;
      case '2': // Menú de temperaturas
        pantalla_temperaturas();
        break;
      case '3': // Purgar / prueba de corte
        probar_actuador();
        break;
      case '4': // Encender/Apagar calentadores
        conmutar_calefaccion();
        break;
      case '5': // Avance manual de película
        jog_arrastre_manual();
        break;
      case 'D': // Menú de configuración
        menu_principal_opciones();
        break;
    }
  }
}

/* ========================================================================== */
/* SUPERVISIÓN CONCURRENTE DE ENTRADAS LOCALES Y REMOTAS                      */
/* ========================================================================== */
char supervisar_entradas() {
  // 1. Revisión de tecla física matricial
  TECLA = teclado.getKey();
  if (TECLA) {
    Serial.println("TECLA_LOCAL:" + String(TECLA));
    return TECLA;
  }

  // 2. Revisión de comandos serie USB desde Visual Basic
  char comando_remoto = procesar_serial();
  if (comando_remoto != 0) {
    return comando_remoto;
  }

  // 3. Revisión de pulsador externo de arrastre manual
  if (leer_arrastre_manual() == HIGH) {
    jog_arrastre_manual();
  }

  // 4. Parada de emergencia física
  if (leer_parada_emergencia() == LOW) {
    detener_maquina();
  }

  // 5. Envío periódico de telemetría hacia Visual Basic (cada 1000 ms en reposo)
  enviar_telemetria_periodica(estado_maquina, 1000);

  return 0;
}

/* ========================================================================== */
/* GESTIÓN DE PARÁMETROS EN EEPROM                                            */
/* ========================================================================== */
void cargar_valores() {
  EEPROM.get(0, clave_acceso);
  EEPROM.get(5, tiempo_sellado);
  EEPROM.get(10, tiempo_arrastre);
  EEPROM.get(35, tiempo_mordaza_cierra);
  EEPROM.get(40, tiempo_mordaza_abre);
  EEPROM.get(55, usar_fc_mordaza);
  EEPROM.get(60, usar_sensor_taca);
  EEPROM.get(65, contador_bolsas);
  EEPROM.get(70, secuencia_operacion);
  EEPROM.get(90, tipo_maquina);
  EEPROM.get(100, temp_consigna_sup_izq);
  EEPROM.get(105, temp_consigna_sup_der);
  EEPROM.get(110, temp_consigna_inf_ext);
  EEPROM.get(115, temp_consigna_inf_int);

  // Valores por defecto seguros si la memoria está en blanco
  if (tiempo_sellado <= 0 || tiempo_sellado > 10000) tiempo_sellado = 1000;
  if (tiempo_arrastre <= 0 || tiempo_arrastre > 10000) tiempo_arrastre = 400;
  if (tiempo_mordaza_cierra <= 0 || tiempo_mordaza_cierra > 5000) tiempo_mordaza_cierra = 400;
  if (tiempo_mordaza_abre <= 0 || tiempo_mordaza_abre > 5000) tiempo_mordaza_abre = 400;
  if (clave_acceso <= 0) clave_acceso = 1234;
  if (temp_consigna_sup_izq <= 0 || temp_consigna_sup_izq > 300) temp_consigna_sup_izq = 150;
  if (temp_consigna_sup_der <= 0 || temp_consigna_sup_der > 300) temp_consigna_sup_der = 150;
  if (temp_consigna_inf_ext <= 0 || temp_consigna_inf_ext > 300) temp_consigna_inf_ext = 150;
  if (temp_consigna_inf_int <= 0 || temp_consigna_inf_int > 300) temp_consigna_inf_int = 150;
}

void guardar_valores() {
  EEPROM.put(0, clave_acceso);
  EEPROM.put(5, tiempo_sellado);
  EEPROM.put(10, tiempo_arrastre);
  EEPROM.put(35, tiempo_mordaza_cierra);
  EEPROM.put(40, tiempo_mordaza_abre);
  EEPROM.put(55, usar_fc_mordaza);
  EEPROM.put(60, usar_sensor_taca);
  EEPROM.put(65, contador_bolsas);
  EEPROM.put(70, secuencia_operacion);
  EEPROM.put(90, tipo_maquina);
  EEPROM.put(100, temp_consigna_sup_izq);
  EEPROM.put(105, temp_consigna_sup_der);
  EEPROM.put(110, temp_consigna_inf_ext);
  EEPROM.put(115, temp_consigna_inf_int);
}

void restablecer_valores_fabrica() {
  tiempo_sellado = 1000;
  tiempo_arrastre = 400;
  tiempo_mordaza_cierra = 400;
  tiempo_mordaza_abre = 400;
  usar_fc_mordaza = 0;
  usar_sensor_taca = 0;
  secuencia_operacion = 0;
  tipo_maquina = 0;
  clave_acceso = 1234;
  temp_consigna_sup_izq = 150;
  temp_consigna_sup_der = 150;
  temp_consigna_inf_ext = 150;
  temp_consigna_inf_int = 150;
  guardar_valores();
}
