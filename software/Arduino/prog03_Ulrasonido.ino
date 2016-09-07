//programa test de ultrasonido
// Junio 2016
// Manuel-LeoBot

//declaracion de variables
long distancia;
long tiempo;

//funcion de configuracion
void setup(){
  Serial.begin(9600);
  pinMode(10, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(11, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

//funcion principal
void loop(){
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
  delay(1000);  //retardo de 1s para visualizar el valor de la distancia
}
