
const int echoPin = 7; 
const int trigPin = 8;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(trigPin, OUTPUT);  //  - Trigger es salida
  pinMode(echoPin, INPUT);   //  - Echo es entrada
  Serial.begin(9600);
}

void loop()
{
  // Generar un pulso de trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // duración del eco
  long duracion = pulseIn(echoPin, HIGH);
  
  // pasar  la distancia en cm
  float distancia = duracion * 0.034 / 2;
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  if(distancia < 10){
    digitalWrite(6, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(3, LOW);
    delay(1000);
  }
  
  if(distancia >= 10){
    digitalWrite(6, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(3, HIGH);
    delay(1000);
  }
}