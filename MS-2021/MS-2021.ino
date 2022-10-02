#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <ModbusMaster.h>

#define MAX485_DE      3
#define MAX485_RE_NEG  2

ModbusMaster node;

const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//byte pinesFilas[FILAS] = {23,25,27,29};   // pines correspondientes a las filas
//byte pinesColumnas[COLUMNAS] = {31,33,35,37}; // pines correspondientes a las columnas

byte pinesFilas[FILAS] = {37,35,33,31};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] ={29,27,25,23} ; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto
//String salida_actual="00000";
char TECLA;       // almacena la tecla presionada


//const int rs = 49, en = 47, d4 = 45, d5 =43, d6 = 41, d7 = 39;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal_I2C lcd(0x27,20,4);

byte pbar[8] = {
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
  0b00011111,
};

byte flecha_sube[8] = {
  0b00000100,
  0b00001110,
  0b00011111,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
};

byte flecha_baja[8] = {
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00000100,
  0b00011111,
  0b00001110,
  0b00000100,
};
//lcd.write((byte)0);

//VARIABLES-------------------------------------------------------------

int AUX3=13;
int AUX2=12;
int AUX1=11;
int mordazas=10;
int actuador=9;
int dos_baja=8;
int dos_sube=7;
int arrastre=6;



int sw_dosificador=A0;
int fc_mordazas=A1;
int fc_dosificador=A2;
int PE = A3;
int taca=A4;
int AR=A5;

int var_clave;
int var_clave1;
int t_sellado;
int ar_prearrastre;
int ar_arrastre;
int ar_arrastre_m;
int ar_doss;
int ar_dosb;
int ar_purs;
int ar_purb;
int ar_actd;
int ar_actc;
int ar_morc;
int ar_mora;
int fc_mor;
int s_taca;
long contador=0;
int var_menu;

int con=0;
long total_settemp=0;
long total_gettemp=0;
long prom_20=0;
long prom_100=0;
int sec=0;
int m_dos=0;
int tipo_maq=0;

double env_inicio=0;
double env_fin=0;
double env_tiempo=0;

//-----------------------------------------------------------------------


void setup() {
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);  
  pinMode(mordazas,OUTPUT); 
  pinMode(dos_sube,OUTPUT);
  pinMode(dos_baja,OUTPUT);
  pinMode(actuador,OUTPUT);
  pinMode(arrastre,OUTPUT);

  pinMode(sw_dosificador,INPUT);
  pinMode(fc_mordazas,INPUT);
  pinMode(fc_dosificador,INPUT);
  pinMode(PE,INPUT);
  pinMode(taca,INPUT);  
 
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.createChar (0, pbar);
  lcd.createChar (1, flecha_sube);
  lcd.createChar (2, flecha_baja);
  lcd.begin(20, 4);
  cargar_valores();
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  Serial1.begin(9600);             
  node.begin(7,Serial1); 
  node.preTransmission(preTransmission);         //Callback for configuring RS-485 Transreceiver correctly
  node.postTransmission(postTransmission);
  scr_bienvenido();
  for (int j=7; j<11;j++){
    set_estado(j,"Off");
  }
  scr_modelo();
  scr_calentar();
  //set_temp(7,10);
}
void loop() {
  scr_inicio();  
}
void iniciar(){ 
 
}
void scr_inicio(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0,1);
  lcd.print("1)INICIAR   3)PURGA");
  lcd.setCursor(0,2);
  lcd.print("2)TEMP.     4)ON/OFF");
  lcd.setCursor(0,3);
  lcd.print("5)ARRASTRE  D)MENU"); 
  for(int i=0;i<1;i){ 
    //jog_arrastre();   
    switch(tec()){
      case '1':
        envasar();       
        break;
      case '2':  
        var_menu=2;
        opc_menu();       
        break;
      case '3':  
        purgar();       
        break;
      case '4':  
        var_menu=1;
        opc_menu();
        scr_inicio();      
        break;
      case '5':  
        var_menu=8;
        opc_menu();
        scr_inicio();      
        break;
      case 'A':  
        salida_on(arrastre);
        delay(ar_arrastre);        
        break;
      case 'D':  
        var_menu=0;
        opc_menu();
        scr_inicio();
        break;
      case 'C':  
        scr_calentar();
        break;
      default:
        salida_off(arrastre);
        break;
    } 
    jog_arrastre();            
  } 
  
}
void scr_bienvenido(){
  lcd.clear();
  lcd.setCursor(4, 1);
  lcd.print("BIENVENIDO!!!");
  delay(5000);
}
void scr_modelo(){
  lcd.clear();
  lcd.setCursor(8, 1);
  lcd.print("JACS");
  lcd.setCursor(3, 2);
  if(tipo_maq==0){
    lcd.print("SLSC-MS 2021LC");
  }
  else{
    lcd.print("SLSO-MS 2021LC");
  }  
  delay(5000);
}
void scr_calentar(){
  lcd.clear();
  lcd.setCursor(1, 1);
  lcd.print("CALENTAR MORDAZAS?");
  lcd.setCursor(8, 2);
  lcd.print("1)SI");
  lcd.setCursor(8, 3);
  lcd.print("2)NO");
  for(int i=0;i<1;i){
    switch(tec()){
      case '1':
        for (int j=7; j<11;j++){
          set_estado(j,"On");
        }
        scr_calentando();;
        break; 
      case '2': 
        for (int j=7; j<11;j++){
          set_estado(j,"Off");
        }
        scr_inicio();
        break; 
    }         
  }  
}
void scr_calentando(){
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(2, 2);
  lcd.print("calentando(0%)");
  if(tipo_maq==1){
    total_settemp=get_set(7)+get_set(8)+get_set(9)+get_set(10);
  }
  else{
    total_settemp=get_set(7)+get_set(9)+get_set(10);
  }
  con=40;
  for(int i=0;i<1;i){
    TECLA = teclado.getKey();
    if (TECLA){
      switch(TECLA){
        case 'D':  
          scr_inicio();        
          break;
        case '*':  
          scr_calentar();
          break;
      }    
    } 
    if(con==40){
      if(tipo_maq==1){     
        total_gettemp=get_temp(7)+get_temp(8)+get_temp(9)+get_temp(10); 
      }
      else{
        total_gettemp=get_temp(7)+get_temp(9)+get_temp(10); 
      }
      prom_20=((20* total_gettemp)/total_settemp);
      prom_100=((100* total_gettemp)/total_settemp);
      lcd.setCursor(2, 2);
      lcd.print("calentando(" +  String(prom_100) + "%)"); 
      lcd.setCursor(0,3);
      if (prom_20>20){
        prom_20=20;    
      }
      if (prom_100>=99){
      prom_100=100;
      lcd.setCursor(2, 2);
      lcd.print("calentando(" +  String(prom_100) + "%)"); 
      delay(2000);
      scr_inicio();     
      }
      for(int j=0;j<prom_20;j++){        
        lcd.write((byte)0);
      }      
      con=0;
    }
    con++;   
    delay(500);
  }   
}
void get_temperaturas(){
  int cont=0;
ini:    
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);  
  lcd.print("SUP I(" + String(get_temp(7)) + ")");
  lcd.setCursor(10, 1);  
  lcd.print("SUP D(" + String(get_temp(8)) + ")");  
  
  lcd.setCursor(0, 2);
  lcd.print("INF E(" + String(get_temp(9)) + ")");
  lcd.setCursor(10, 2);
  lcd.print("INF I(" +String(get_temp(10)) + ")");
  
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar    D)Set");
   for(int i=0;i<1;i){
    TECLA = teclado.getKey();
    if (TECLA){
      switch(TECLA){
        case '*':  
          return;        
          break;
        case 'A':  
          goto ini;
          return;        
          break;
        case 'D':
          set_temperaturas(); 
          goto ini;       
          break;
      }    
    } 
    delay(100);
    cont++;
    if (cont>=50){
      cont=0;
      goto ini;      
    }
  }  
}


void set_temperaturas(){  
ini:
  int val=0;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("JACS MAQUINAS");
  lcd.setCursor(0, 1);  
  lcd.print("1)SI(" + String(get_set(7)) + ")");
  lcd.setCursor(10, 1);  
  lcd.print("2)SD(" + String(get_set(8)) + ")");  
  
  lcd.setCursor(0, 2);
  lcd.print("3)IE(" + String(get_set(9)) + ")");
  lcd.setCursor(10, 2);
  lcd.print("4)II(" +String(get_set(10)) + ")");
  
  lcd.setCursor(0, 3);
  lcd.print("*)Regresar");
   for(int i=0;i<1;i){
    TECLA = teclado.getKey();
    if (TECLA){
      switch(TECLA){
        case '1': 
          val=input_int("INGRESE T SUP I",0,200,"C");
          if (val > -1){
            set_temp(7,val);
          }
          goto ini;
          return;        
          break;
        case '2': 
          val=input_int("INGRESE T SUP D",0,200,"C");
          if (val > -1){
            set_temp(8,val);
          }
          goto ini;
          return;        
          break;
        case '3': 
          val=input_int("INGRESE T INF E",0,200,"C");
          if (val > -1){
            set_temp(9,val);
          }
          goto ini;
          return;        
          break;
        case '4': 
          val=input_int("INGRESE T INF I",0,200,"C");
          if (val > -1){
            set_temp(10,val);
          }
          goto ini;
          return;        
          break;
        case '*':         
          return;        
          break;
      }    
    } 
  }  
}

void purgar(){
  lcd.clear();
  lcd.print("       PURGAR");
  lcd.setCursor(0, 2);
  lcd.print(" SW DOSIFICADOR(" + String(sd()) +")");
  lcd.setCursor(0, 3);
  lcd.print("*)Inicio");
  for(int i=0;i<1;i){
    switch(tec()){
      case '*':
        scr_inicio();
        break;
    }
    if (sd()==1){
      lcd.setCursor(16, 2);
      lcd.print(String(sd()) +")");
      salida_off(dos_baja);
      salida_on(actuador);
      delay(ar_actd);
      salida_on(dos_sube);
      delay(ar_purs);
      salida_off(actuador);
      delay(ar_actc);
      salida_off(dos_sube);
      salida_on(dos_baja);
      delay(ar_purb);
    } 
  lcd.setCursor(16, 2);
  lcd.print(String(sd()));  
  } 
}
char tec(){
  TECLA = teclado.getKey();
  if (TECLA){
    return(TECLA);
  }
}






boolean regresar(){
  TECLA = teclado.getKey();
  Serial.println(TECLA);
  if (TECLA=='*'){       
      //detener pulsos
      lcd.clear();
      lcd.print("   JACS MAQUINAS");
      lcd.setCursor(3, 3);
      lcd.print("Finalizando...");  
      delay(500); 
      return true;     
  } 
  else{
    return false;
  }
} 
boolean acceso(){
  var_clave1=input_clave("INGRESE CLAVE",0,999999,"");
  if (var_clave1==var_clave){
    msgbox_acceso(true);
    return(true);
  }
  else{
    msgbox_acceso(false);
    return(false);
  }
}
void cargar_valores(){ 
  EEPROM.get(0, var_clave );
  EEPROM.get(5, t_sellado );
  EEPROM.get(10,ar_arrastre );
  EEPROM.get(15,ar_doss );
  EEPROM.get(20,ar_dosb );
  EEPROM.get(25,ar_purs );
  EEPROM.get(30,ar_purb );
  EEPROM.get(35,ar_actd );
  EEPROM.get(40,ar_actc );
  EEPROM.get(45,ar_morc );
  EEPROM.get(50,ar_mora );
  EEPROM.get(55,fc_mor );
  EEPROM.get(60,s_taca );
  EEPROM.get(65,contador );
  EEPROM.get(70,sec );
  EEPROM.get(75,m_dos );
  EEPROM.get(80,ar_arrastre_m );
  EEPROM.get(85,ar_prearrastre );
  EEPROM.get(90,tipo_maq );
}
void reset_contador(){ 
  contador=0;
  EEPROM.put(65,contador);
}
void reset_valores(){ 
  EEPROM.put(0, 1234 );    //var_clave
  EEPROM.put(5, 1000 );    //t_sellado
  EEPROM.put(10,400 );     //ar_arrastre
  EEPROM.put(15,1000 );     //ar_doss
  EEPROM.put(20,1000 );     //ar_dosb
  EEPROM.put(25,1000 );     //ar_purs
  EEPROM.put(30,1000 );     //ar_purb
  EEPROM.put(35,200 );     //ar_actd
  EEPROM.put(40,200 );     //ar_actc
  EEPROM.put(45,400 );     //ar_morc
  EEPROM.put(50,400 );     //ar_mora
  EEPROM.put(55,0 );       //fc_mor
  EEPROM.put(60,0 );       //s_taca
  //EEPROM.put(65,0 )      //contador
  EEPROM.put(70,0 );       //sec
  EEPROM.put(75,1 );       //m_dos
  EEPROM.put(80,400 );     //ar_arrastre_m
  EEPROM.put(85,0 );      //ar_prearrastre
  EEPROM.put(90,0 );      //tipo_maq
}   
