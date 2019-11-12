#include <SPI.h>
#include <Controllino.h>
#include "MaquetaProcessing.h";


//int pulsadorInicio = CONTROLLINO_A7;
int girarMesa = CONTROLLINO_R1;
int girarBrocaTaladro = CONTROLLINO_R0;
Outputs irt;

// Resto de salidas digitales
// Process data... Etapas (bool), por ejemplo


void setup() {
  // put your setup code here, to run once:

  // Init serial
  Serial.begin(115200);
  // Init I/O. Realmente no hace falta. El funcionamiento como entrada del pin está preestablecido
  initHardware();
  /*
  pinMode(entradas.piezaEnPuestoDeEntrada, INPUT);
  pinMode(entradas.piezaEnPuestoDeMecanizado, INPUT);
  pinMode(entradas.piezaEnPuestoDeComprobacion,INPUT);
  pinMode(entradas.cabezalDelTaladroEnPosicionSuperior, INPUT);
  pinMode(entradas.cabezalDelTaladroEnPosicionInferior, INPUT);
  pinMode(entradas.mesaGiratoriaEnPosicion,INPUT);
  
  pinMode(entradas.pulsadorDeInicio, INPUT);
  pinMode(entradas.pulsadorDeParada, INPUT);
  pinMode(entradas.selectorManualAutomatico,INPUT);
  pinMode(entradas.pulsadorDeReset, INPUT);
  pinMode(entradas.setaDeEmergencia, INPUT);


  */

  
  // Resto de entradas digitales
  // Realmente no hace falta. El funcionamiento como salida del pin está preestablecido
/*  pinMode(pinSalidaDigital_K1_M1, OUTPUT);
  pinMode(pinSalidaDigital_K2_M2, OUTPUT);
  pinMode(pinSalidaDigital_K3_M3, OUTPUT);*/
  // Resto de salidas digitales
  // Activar etapa(s) inicial(es)
  // Allow the hardware to sort itself out
  delay(1500);

}

void loop() {
  
  Inputs in = irakurriSentsoreSarrerak();

  if(!in.setaDeEmergencia){
    irt.girarMesa = 0;  
    irt.bajarTaladro = 0;
    irt.girarBrocaDelTaladro = 0;
    //irt.subirTaladro = 0; //TODO: No va 
    /*
  int accionarEmpujador;
  int accionarComprobador;*/
  }
  else{
  
    if(in.pulsadorDeInicio){
      irt.bajarTaladro = 1;
      irt.subirTaladro = 0;
      /*digitalWrite(girarMesa,HIGH);
      Serial.print("Leyendo \n");
      digitalWrite(girarBrocaTaladro,HIGH);  */
    }
    else{
      irt.girarBrocaDelTaladro = 0;
      irt.subirTaladro = 1;
      irt.bajarTaladro = 0;
     }

     if(in.selectorManualAutomatico){ 
      irt.girarBrocaDelTaladro = 1;
      
     }
     else{
      irt.girarBrocaDelTaladro = 0;
      
     }

    if( in.pulsadorDeReset) irt.accionarExpulsor = 1;
    else irt.accionarExpulsor = 0;
  
    if(in.pulsadorDeParada) irt.girarMesa = 0;
    else irt.girarMesa = 1;
  
    
    idatziAktuadoreenBalioak(irt);
  }
  // Retardo
  delay(10);
  
}


void initHardware(){
  pinMode(Part_AV, INPUT);
  pinMode(B_2, INPUT);
  pinMode(B_1, INPUT);
  pinMode(_1B1, INPUT);
  pinMode(_1B2, INPUT);
  pinMode(B_3, INPUT);
  pinMode(B_4, INPUT);
  pinMode(S_1, INPUT);
  pinMode(S_2, INPUT);
  pinMode(S_3, INPUT);
  pinMode(S_4, INPUT);
  pinMode(Em_Stop, INPUT);


}


Inputs irakurriSentsoreSarrerak(){
  Inputs sarrerak;
  sarrerak.piezaEnPuestoDeEntrada = digitalRead(Part_AV);
  sarrerak.piezaEnPuestoDeMecanizado = digitalRead(B_2);
  sarrerak.piezaEnPuestoDeComprobacion = digitalRead(B_1);
  sarrerak.cabezalDelTaladroEnPosicionSuperior = digitalRead(_1B1);
  sarrerak.mesaGiratoriaEnPosicion = digitalRead(B_3); //ESTO QUE ES?
  sarrerak.comprobacionOK = digitalRead(B_4);
  sarrerak.pulsadorDeInicio = digitalRead(S_1);
  sarrerak.pulsadorDeParada = digitalRead(S_2);
  sarrerak.selectorManualAutomatico = digitalRead(S_3);
  sarrerak.pulsadorDeReset = digitalRead(S_4);
  sarrerak.setaDeEmergencia = digitalRead(Em_Stop);
  
  return sarrerak;
}

void idatziAktuadoreenBalioak(Outputs irteerak){

  if(irteerak.girarBrocaDelTaladro) digitalWrite(K1_M3,HIGH);
  else digitalWrite(K1_M3,LOW);

  if(irteerak.girarMesa) digitalWrite(K2_M2,HIGH);
  else digitalWrite(K2_M2, LOW);

  if(irteerak.bajarTaladro) digitalWrite(K3_M1,HIGH);
  else digitalWrite(K3_M1, LOW);

  if(irteerak.subirTaladro) digitalWrite(K4_M1,HIGH);
  else digitalWrite(K4_M1, LOW);

  if(irteerak.accionarEmpujador) digitalWrite(M_4,HIGH);
  else digitalWrite(M_4, LOW);

  if(irteerak.accionarExpulsor) digitalWrite(M_6,HIGH);
  else digitalWrite(M_6, LOW);

  if(irteerak.indicadorDeInicio) digitalWrite(P_1,HIGH);
  else digitalWrite(P_1, LOW);
  
  if(irteerak.indicadorDeReset) digitalWrite(P_2,HIGH);
  else digitalWrite(P_2, LOW);

  //TODO: Check -> Casca al compilar
  /*
  if(irteerak.indicadorDePiezaIncorrecta) digitalWrite(P_3,HIGH);
  else digitalWrite(P_3, LOW);
  */
  
  }
