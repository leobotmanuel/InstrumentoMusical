/* prog01_leds
 *  prueba el funcionamiento de los led
 *  
 *  Mayo-2016, LeoBot-Manuel
 */

#include "pitches.h"


int Do = 2;
int Re = 3;
int Mi = 4;
int Fa = 5;
int Sol = 6;
int La = 7;
int Si = 8;
int Do8 = 9;


void setup(void) {
  Serial.begin(9600);
 
  pinMode(Do, OUTPUT);
  pinMode(Re, OUTPUT);
  pinMode(Mi, OUTPUT);
  pinMode(Fa, OUTPUT);
  pinMode(Sol,OUTPUT);
  pinMode(La, OUTPUT);
  pinMode(Si, OUTPUT);
  pinMode(Do8, OUTPUT);
}

void loop() {
  for (int i = 2; i < 10; i++) {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
}


