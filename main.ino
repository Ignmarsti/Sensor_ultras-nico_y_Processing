// Incluye la biblioteca Servo
#include <Servo.h>. 

// Define los pines Tirg y Echo del sensor ultrasónico
const int trigPin = 10;
const int echoPin = 11;

// Variables para la duración y la distancia
long duration;
int distance;
Servo myServo; //Crea un objeto servo para controlar el servomotor

void setup() {
  pinMode(trigPin, OUTPUT); // Establece el trigPin como salida
  pinMode(echoPin, INPUT); // Establece el echoPin como entrada
  Serial.begin(9600);
  myServo.attach(12); //  Define en qué pin está conectado el servomotor
}
void loop() {
   // gira el servomotor de 15 a 165 grados
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();//  Llama a una función para calcular la distancia medida por el sensor ultrasónico para cada grado
 
  
  Serial.print(i); // Envía el grado actual al puerto serie
  Serial.print(","); // Envía un carácter que reconocerá el el Processing
  Serial.print(distance); // Envía el valor de la distancia al puerto serie
  Serial.print("."); //  Envía un carácter que reconocerá el Processing
  }
  // Repite las líneas anteriores de 165 a 15 grados
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Función para calcular la distancia medida por el sensor ultrasónico
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Establece el trigPin en estado ALTO durante 10 microsegundos
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Lee el echoPin, devuelve el tiempo de viaje de la onda de sonido en microsegundos
  distance= duration*0.034/2;
  return distance;
}