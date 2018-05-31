
//PROYECTO DE BRAZO ROBOTICO DISEÑADO POR SAMUEL FELIPE VARGAS ROJAS Y MATEO FELIPE TORRES BRAZO, ESTUDIANTES DE SEGUNDO SEMESTRE DE INGENIERIA ELECTRONICA
//UNIVERSIDAD DEL QUINDIO,AÑO 2018
//VERSION 1.0

#include <Servo.h> // Libreria para controlar los servomotores

//////////////////////////// definicion de variables con respecto a pines del arduino

#define pinBase 5  
#define pinCodo 4
#define pinBrazo 6
#define pinGarra 7 
#define initBase 75
#define initCodo 90  
#define initBrazo 10
#define initGarra 160

////////////////////// definicion de servos

Servo Base;
Servo Codo;
Servo Brazo;
Servo Garra;

//////////////////////// definimos variables enteras y la matriz

int matriz [4][20]={{10,20,30,40,50,60,70,80,87,93,110,120,130,140},{100,120,130,140,150,160,170,180,190},{85,95,105,110,120,130,140,150,160,170,180},{}    };
int i,val=0;
int angulo=13;
int valorgarra,valorbrazo,valorcodo,valorbase;

void setup() 
{

  ///////////////////// inicializacion del brazo
  
  Base.attach (pinBase);
  Codo.attach (pinCodo);
  Brazo.attach (pinBrazo);
  Garra.attach (pinGarra);
  Base.write (initBase);
  Base.write (initBase +60);
  delay (500);
  Base.write (initBase -50);
  delay (500);
  Base.write (initBase);
  delay (500);
  Codo.write (initCodo);
  delay (500);
  Codo.write (initCodo -70);
  delay (500);
  Codo.write (initCodo);
  delay (500);
  Brazo.write (initBrazo);
  delay (500);
  Brazo.write (initBrazo +50);
  delay (500);
  Codo.write (initCodo);
  delay (500);
  Codo.write (initCodo -70);
  delay (500);
  Codo.write (initCodo);
  delay (500);
  Codo.write (initCodo -70);
  delay (500);
  Garra.write (initGarra);
  delay (200);
  Garra.write (initGarra -45); // la garra el angulo recto es con 90°
  delay (200);
  Garra.write (initGarra);
  delay (200);
  Garra.write (initGarra -45);
  delay (200);
  Garra.write (initGarra);
  delay (200);
  Garra.write (initGarra -45);
  delay (200);
  Garra.write (initGarra);
  Serial.begin(9600);

  }


  void loop() 
  {

  val=Serial.read();

  if(val=='h'){

///////////////////////////////// pocision incial de servos

  Base.write(72);
  delay(100);
  Codo.write(40);
  delay(100);
  Garra.write(90);
  delay(100);

  //////////////////////////////// Movimiento incial de brazo

  Brazo.write(matriz[0][0]);
  delay(100);
  Brazo.write(matriz[0][1]);
  delay(100);
  Brazo.write(matriz[0][2]);
  delay(100);
  Brazo.write(matriz[0][3]);
  delay(100);
  Brazo.write(matriz[0][5]);
  delay (100);
  Brazo.write(matriz[0][4]);
  delay(100);
  Brazo.write(matriz[0][5]);
  delay(100);
  Brazo.write(matriz[0][6]);
  delay(100);
  Brazo.write(matriz[0][7]);
  delay(100);
  Brazo.write(matriz[0][8]);
  delay (100);
  Brazo.write(matriz[0][9]);
  delay (100);
  Codo.write(matriz[0][6]);
  delay(100);
  Codo.write(matriz[0][5]);
  delay(100);
  Codo.write(matriz[0][4]);
  delay(100);
  Codo.write(matriz[0][3]);
  delay(100);

  ////////////////////////// cerrado de garra

  Garra.write(170);
  Garra.write(matriz[1][0]);
  delay(100);
  Garra.write(matriz[1][1]);
  delay(100);
  Garra.write(matriz[1][2]);
  delay(100);
  Garra.write(matriz[1][3]);
  delay(100);
  Garra.write(matriz[1][4]);
  delay(100);
  Garra.write(matriz[1][5]);
  delay(100);
  Garra.write(matriz[1][6]);
  delay(100);
  Garra.write(matriz[1][7]);
  delay(100);

  ////////////////////////// levantamiento de brazo

  Brazo.write(matriz[0][8]);
  delay(100);
  Brazo.write(matriz[0][7]);
  delay(100);
  Brazo.write(matriz[0][6]);
  delay(100);
  Brazo.write(matriz[0][5]);
  delay(100);
  Brazo.write(matriz[0][4]);
  delay(100);
  Brazo.write(matriz[0][3]);
  delay(100);
  Codo.write(matriz[0][3]);
  delay(100);
  Codo.write(matriz[0][4]);
  delay(100);
  Codo.write(matriz[0][5]);
  delay(100);
  Codo.write(matriz[0][6]);
  delay(100);
  Codo.write(matriz[0][7]);
  delay(100);
  Codo.write(matriz[0][8]);
  delay(100);

  //////////////////////////// movimiento de base

  Base.write(matriz[2][0]);
  delay(100);
  Base.write(matriz[2][1]);
  delay(100);
  Base.write(matriz[2][2]);
  delay(100);
  Base.write(matriz[2][3]);
  delay(100);
  Base.write(matriz[2][4]);
  delay(100);
  Base.write(matriz[2][5]);
  delay(100);
  Base.write(matriz[2][6]);
  delay(100);
  Base.write(matriz[2][7]);
  delay(100);
  Base.write(matriz[2][8]);
  delay(100);
  Base.write(matriz[2][9]);
  delay(100);
  Base.write(matriz[2][10]);
  delay(100);

  /////////////////////// movimiento final de garra

  Garra.write(matriz[1][7]);
  delay(100);
  Garra.write(matriz[1][6]);
  delay(100);
  Garra.write(matriz[1][5]);
  delay(100);
  Garra.write(matriz[1][4]);
  delay(100);
  Garra.write(matriz[1][3]);
  delay(100);
  Garra.write(matriz[1][2]);
  delay(100);
  Garra.write(matriz[1][1]);
  delay(100);
  Garra.write(matriz[1][0]);
  delay(100);
      
  }
  
  ///////////////////////// movimiento de garra
  
  if(val=='3'){   
    valorgarra=valorgarra-angulo;     
  Garra.write(valorgarra);                 
  delay(15);}
  
  
  if(val=='0'){
    valorgarra=valorgarra+angulo;
    Garra.write(valorgarra);
    delay(15);}

     
    //////////////////////// pocision de seguridad para reiniciar todos los servos sin necesidad de reiniciar arduino
     
     if(val=='5'){
    Brazo.write(10);
    delay(15);
    Codo.write(90);
    delay(15);
    Garra.write(160);
    delay(15);
    Base.write(75);
    delay(15);}
     
     
     ///////////////////// movimiento de brazo
     
     if(val=='2'){
      valorbrazo=valorbrazo-angulo;
    Brazo.write(valorbrazo);
    if (valorbrazo<=10) valorbrazo=10;
    delay(15);}
     
     
     if(val=='8'){
      valorbrazo=valorbrazo+angulo;
    Brazo.write(valorbrazo);
    if (valorbrazo>=170) valorbrazo=170;
    delay(15);}
     
     
     /////////////////////// movimiento de codo
     
     if(val=='9'){
      valorcodo=valorcodo+angulo;
    Codo.write(valorcodo);
    if (valorcodo>=170) valorcodo=170;
    delay(15);}
     
     
     if(val=='7'){
      valorcodo=valorcodo-angulo;
    Codo.write(valorcodo);
    if (valorcodo<=10) valorcodo=10;
    delay(15);}
     
     
     ///////////////////// movimiento de base
     
     if(val=='4'){
      valorbase=valorbase+angulo;
    Base.write(valorbase);
    if (valorbase>=175) valorbase=175;
    delay(15);}
    
    
    if(val=='6'){
      valorbase=valorbase-angulo;
    Base.write(valorbase);
    if (valorbase<=5) valorbase=5;
    delay(15);}

  }



  
  


