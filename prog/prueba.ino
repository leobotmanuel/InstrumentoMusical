#include <Servo.h>

//Etiquetas de identificaciÃ³n de los pines
const int motorB_Dir1 = 12;        //pines para controlar la direccion de giro
const int motorB_Dir2 = 13;
const int motorB_Velocidad = 11;  //salida PWM para controlar la velocidad

//Variables
int vPWM = 155;    //valor de la velocidad en PWM

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object

  //configuracion de los pines
  pinMode(motorB_Dir1, OUTPUT);
  pinMode(motorB_Dir2, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

   //Activamos el motor B en un sentido de giro
  digitalWrite(motorB_Dir1,HIGH);
  digitalWrite(motorB_Dir2,LOW); 
  analogWrite(motorB_Velocidad,vPWM);
  delay(5000);                //permanece activado 5s
  
  //Paramos el motor durante 2 segundo
  digitalWrite(motorB_Dir1,LOW);
  digitalWrite(motorB_Dir2,LOW);
  delay(2000);
  
  //Activamos el motor B en un sentido de giro
  digitalWrite(motorB_Dir1,LOW);
  digitalWrite(motorB_Dir2,HIGH); 
  analogWrite(motorB_Velocidad,vPWM);
  delay(5000);                //permanece activado 5s
  
  //Paramos el motor durante 1 segundo
  digitalWrite(motorB_Dir1,LOW);
  digitalWrite(motorB_Dir2,LOW);
  delay(2000);

}
