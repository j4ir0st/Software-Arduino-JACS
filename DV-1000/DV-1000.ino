#include "Header.h"

/* ========================================================================== */
/* CONFIGURACIÓN INICIAL DEL SISTEMA (SETUP)                                  */
/* ========================================================================== */

void setup() {
  /* Define las entradas y salidas de los pines de actuadores */
  pinMode(fina, OUTPUT); 
  pinMode(gruesa, OUTPUT); 
  pinMode(m_abre, OUTPUT); 
  pinMode(m_cierra, OUTPUT); 
  pinMode(PE, INPUT_PULLUP);                        // Parada de emergencia con resistencia pull-up interna
  /* -------------------------------------------------------- */

  /* Inicialización de periféricos: Puerto serie USB, Celda de carga y LCD */
  Serial.begin(9600);
  celda.begin(PIN_HX711_DAT, PIN_HX711_CLK);
  
  /* Inicialización de módulo IoT / Cloud y lectura de número de serie en EEPROM */
  inicializar_iot();
  
  lcd.init();
  lcd.backlight();

  /* Configuración de teclado para máxima reactividad */
  teclado.setDebounceTime(10);
  teclado.setHoldTime(300);

  /* Crea caracteres personalizados en memoria del LCD */
  lcd.createChar(0, barra_progreso);
  lcd.createChar(1, flecha_sube);
  lcd.createChar(2, flecha_baja);
  /* ------------------------------------------------- */

  /* Mensaje de bienvenida inicial rápido */
  lcd.setCursor(3, 1);
  lcd.print("JACS MAQUINAS");
  delay(800);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("DOSIFICADOR");
  lcd.setCursor(6, 1);
  lcd.print("DV-1000");
  lcd.setCursor(0, 2);
  lcd.print("SN:" + sn_maquina);
  lcd.setCursor(11, 3);
  lcd.print("V2022.0.2");
  cargar_valores();
  delay(1200);
  /* ----------------------------- */

  /* Calibración inicial de tara */
  calibracion_tara();
  /* -------------------------------------------------------- */
}

/* ========================================================================== */
/* BUCLE PRINCIPAL DE OPERACIÓN (LOOP)                                        */
/* ========================================================================== */
void loop() {
  /* Imprime pantalla principal de funcionamiento de la máquina */
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("1)INICIAR");
  lcd.setCursor(0, 2);
  lcd.print("2)PESO(" + String(s_peso) + "gr)");
  lcd.setCursor(0, 3);
  lcd.print("3)VF(" + String(v_fina) + "gr)");
  lcd.setCursor(14, 1);
  lcd.print("4)TARA");
  lcd.setCursor(14, 2);
  lcd.print("#)DESC");
  lcd.setCursor(14, 3);
  lcd.print("D)MENU");
  /* ---------------------------------------------------------- */

  estado_dosificador = "ESPERA";

  /* Espera y despacha órdenes provenientes del teclado físico o de Visual Basic */
  if (tec()){
    switch(TECLA){
      case '1':         
        iniciar();
        break;
      case '2':
        set_peso();
        break;
      case '3':
        v_fina_value();
        break;
      case '4':
        calibracion_tara();
        break;
      case '#':
        descargar();
        break;
      case 'D':
        opc1();
        break;
    }    
  }
}

/* ========================================================================== */
/* SUPERVISIÓN CONCURRENTE: TECLADO LOCAL, COMANDOS USB Y PULSADORES         */
/* ========================================================================== */
/* 
 * tec:
 * Supervisa simultáneamente:
 * 1. Pulsaciones en el teclado físico matricial.
 * 2. Comandos serie recibidos desde Visual Basic vía USB.
 * 3. Botón de Parada de Emergencia (PE) y pulsador manual de descarga.
 * 4. Transmisión periódica del estado en reposo hacia Visual Basic.
 */
char tec(){
  while(1){
    // 1. Lectura inmediata del teclado físico matricial (prioridad máxima sin retardos)
    TECLA = teclado.getKey();
    if (TECLA != NO_KEY){
      return(TECLA);
    }

    // 2. Lectura y procesamiento de comandos serie USB desde Visual Basic
    char comando_remoto = procesar_serial();
    if (comando_remoto != 0){
      TECLA = comando_remoto;
      return(TECLA);
    }

    // 3. Lectura y procesamiento de comandos remotos IoT / Nube (Serial1)
    char comando_iot = procesar_serial_iot();
    if (comando_iot != 0){
      TECLA = comando_iot;
      return(TECLA);
    }

    // 4. Envío de telemetría a Visual Basic (solo si la PC está conectada activamente)
    if (conexion_pc_activa) {
      enviar_telemetria_periodica(estado_dosificador, 1000);
    }

    // 5. Envío periódico de telemetría IoT a la nube / Supabase (Serial1 cada 3 segundos)
    enviar_telemetria_iot_periodica(estado_dosificador, 3000);
  }
}

/* ========================================================================== */
/* CARGA DE PARÁMETROS DESDE LA MEMORIA EEPROM                                */
/* ========================================================================== */
void cargar_valores(){ 
  EEPROM.get( 0, peso_ref );              // Peso referencial de calibración
  EEPROM.get( 10, escala_calibracion );   // Asigna la escala de calibración
  if (isnan(escala_calibracion) || escala_calibracion == 0.0f) {
    escala_calibracion = 1.0f;            // Factor base para evitar división entre cero si no se ha calibrado
  }
  EEPROM.get( 20, s_peso );               // Valor a pesar definido por set_peso
  EEPROM.get( 30, i_modo );               // Modo: 1=Automático 2=Manual
  EEPROM.get( 40, inercia );              // Compensación de inercia
  EEPROM.get( 50, d1 );                   // Retardo apertura descarga
  EEPROM.get( 60, tiempo_descarga );      // Tiempo de descarga del pistón neumático (default 2000 ms)
  if (tiempo_descarga <= 0 || tiempo_descarga > 30000) {
    tiempo_descarga = 2000;
  }
  d2 = tiempo_descarga;
  EEPROM.get( 70, d3 );                   // Retardo cierre descarga
  EEPROM.get( 80, v_fina );               // Rango de vibración fina en gramos
  EEPROM.get( 90, error );                // Margen de error aceptable
  EEPROM.get( 100, peso_max );            // Límite de peso máximo
  EEPROM.get( 110, peso_min );            // Límite de peso mínimo
  EEPROM.get( 120, delay_aut );           // Retardo en modo automático
  EEPROM.get( 140, contador );            // Contador acumulado de descargas
  EEPROM.get( 150, t_ac1 );               // Tiempo de autocorrección 1
  EEPROM.get( 160, t_ac2 );               // Tiempo de autocorrección 2
  EEPROM.get( 170, t_ac3 );               // Tiempo de autocorrección 3
  EEPROM.get( 180, ac_modo );             // 1=Activa, 0=Desactiva la autocorrección
  EEPROM.get( 190, id_dosificador );      // Identificador de tolva (1 a 99)

  // Validación por defecto en caso de memoria EEPROM sin inicializar
  if (id_dosificador <= 0 || id_dosificador > 99) {
    id_dosificador = 1;
  }
}