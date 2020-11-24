#ifndef MAQUETAPROCESSING
#define MAQUETAPROCESSING
#include <SPI.h>
#include <Controllino.h>

/* Puertos de entrada */
int Part_AV = CONTROLLINO_A0;
int B_2 = CONTROLLINO_A1;
int B_1 = CONTROLLINO_A2;
int _1B1 /*= CONTROLLINO_A3*/;
int _1B2 /*= CONTROLLINO_A4*/;
int B_3 = CONTROLLINO_A3; //ESTO QUE ES?
int B_4 = CONTROLLINO_A4;
int S_1 = CONTROLLINO_A5;
int S_2 = CONTROLLINO_A6;
int S_3 = CONTROLLINO_A7;
int S_4 = CONTROLLINO_A8;
int Em_Stop = CONTROLLINO_A9;

/* Puertos de salida */
int K1_M3 = CONTROLLINO_R0;
int K2_M2 = CONTROLLINO_R1;
int K3_M1 = CONTROLLINO_R2;
int K4_M1 = CONTROLLINO_R3;
int M_4 = CONTROLLINO_R4;
int M_5 = CONTROLLINO_R5;
int M_6 = CONTROLLINO_R6;
int P_1 = CONTROLLINO_D0;
int P_2 = CONTROLLINO_D1;
int P_3 = CONTROLLINO_D2;


struct Inputs{
  int piezaEnPuestoDeEntrada;
  int piezaEnPuestoDeMecanizado;
  int piezaEnPuestoDeComprobacion;
  int cabezalDelTaladroEnPosicionSuperior;
  int cabezalDelTaladroEnPosicionInferior;
  int mesaGiratoriaEnPosicion; //ESTO QUE ES?
  int comprobacionOK;
  int pulsadorDeInicio;
  int pulsadorDeParada;
  int selectorManualAutomatico;
  int pulsadorDeReset;
  int setaDeEmergencia;
};

struct Outputs{
  int girarBrocaDelTaladro;
  int girarMesa;
  int bajarTaladro;
  int subirTaladro;
  int accionarEmpujador;
  int accionarComprobador;
  int accionarExpulsor;
  //int estacionLlena; //Que es?
  //int byteDeSalidas; //que es?
  int indicadorDeInicio;
  int indicadorDeReset;
  int indicadorDePiezaIncorrecta;
  // int byteDeSalidasDelPanel //que es?
};


void initHardware();
Inputs irakurriSentsoreSarrerak();
void idatziAktuadoreenBalioak(Outputs irteerak);

#endif
