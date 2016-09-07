/* prog04_ultrasonidoLeds
 *  prueba el funcionamiento de los led
 *  
 *  Mayo-2016, LeoBot-Manuel
 */


//Declaracion de etiquetas de pines
int Do = 2;
int Re = 3;
int Mi = 4;
int Fa = 5;
int Sol = 6;
int La = 7;
int Si = 8;
int Do8 = 9;

//Declaracion de variables
long distancia;
long tiempo;

void setup(void) {
  Serial.begin(9600);
  
  pinMode(10, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(11, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

  pinMode(Do, OUTPUT);
  pinMode(Re, OUTPUT);
  pinMode(Mi, OUTPUT);
  pinMode(Fa, OUTPUT);
  pinMode(Sol,OUTPUT);
  pinMode(La, OUTPUT);
  pinMode(Si, OUTPUT);
  pinMode(Do8, OUTPUT);

//comprueba todos los leds
  for (int i = 2; i < 10; i++) {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);  
  }
}

void loop() {

  distanciaNota();
  
  if ((distancia > 4) && (distancia<8)){
    int i=2; //nota Do
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

    if ((distancia > 8) && (distancia<12)){
    int i=3; //nota Re
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 12) && (distancia<16)){
    int i=4; //nota Mi
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 16) && (distancia<20)){
    int i=5; //nota Fa
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 20) && (distancia<24)){
    int i=6; //nota Sol
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 24) && (distancia<28)){
    int i=7; //nota La
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 28) && (distancia<32)){
    int i=8; //nota Si
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }

   if ((distancia > 32) && (distancia<36)){
    int i=8; //nota Do8
    digitalWrite(i,HIGH);
    //delay(100);
    for (int j = i+1; j < 10; j++)
       digitalWrite(j,LOW);
    for (int j = i-1; j > 1; j--)
       digitalWrite(j,LOW);  
  }
  
   if ((distancia > 4) && (distancia > 32)){
    for (int i = 2; i < 10; i++)
      digitalWrite(i,LOW);  
  }
  
}
//Funciones
void distanciaNota(){
  digitalWrite(10,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(10, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(11, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
                               del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza
                               a recibir el rebote, HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(10);            //retardo de 10ms, realiza las medias de la distancia más rápido
}



