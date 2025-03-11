🤖 Robot Detector de Obstáculos

Control de motores DC mediante sensor ultrasónico HC-SR04
<img src="https://csg.tinkercad.com/things/24tBoFASuUR/t725.png?rev=1739890087306000000&s=&v=1&type=circuits&sharecode=YbCjHmA5aiK8nG-_y7TUza9Ws6-nhKdO7SQaWcRT8VM" alt="conecction" width="400" />

📋 Descripción
Este proyecto implementa un sistema de navegación reactivo utilizando un sensor ultrasónico para controlar el comportamiento de dos motores DC. Perfecto para principiantes en robótica que buscan crear su primer robot con capacidad de detección de obstáculos.
✨ Características

🔍 Detección de obstáculos mediante sensor ultrasónico HC-SR04
⚡ Control bidireccional de dos motores DC
🔄 Comportamiento adaptativo basado en la proximidad
📊 Monitoreo de distancia por puerto serial

🛠️ Componentes
ComponenteCantidadNotasArduino UNO/Nano1Cualquier modelo compatibleSensor HC-SR041Rango 2cm-400cmDriver motores1L298N o similarMotores DC23-6V recomendadoChasis1Opcional, cualquier diseño compatibleBaterías-Según requerimientos de potencia
📌 Diagrama de Conexiones
CopyArduino         HC-SR04       Motores
-------         -------       -------
Pin 8    -->    TRIG
Pin 7    <--    ECHO
Pin 6    -->    Motor1(+)
Pin 10   -->    Motor1(-)
Pin 9    -->    Motor2(+)
Pin 3    -->    Motor2(-)
💻 Código
cppCopyconst int echoPin =.7;  
...
<details>
  <summary>Ver código completo</summary>
cppCopyconst int echoPin = 7; 
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
</details>
🚀 Funcionamiento
El sistema opera con una lógica simple pero efectiva:

🟢 Modo avance: Cuando no hay obstáculos cercanos (≥10cm), el robot avanza
🔴 Modo retroceso: Al detectar un obstáculo próximo (<10cm), ambos motores invierten su giro

📈 Resultados y Comportamiento
Show Image
🛠️ Mejoras Futuras

 Implementar giros para evasión inteligente
 Añadir control PWM para velocidades variables
 Integrar múltiples sensores para mejor navegación
 Desarrollar interfaz de control remoto
 Optimizar consumo de energía

🔧 Solución de Problemas
ProblemaPosible SoluciónLecturas erróneasVerificar conexiones y alimentación del sensorMotores no respondenComprobar driver y voltaje de alimentaciónMovimientos erráticosCalibrar sensor y revisar umbral de distancia
👥 Contribuciones
Las contribuciones son bienvenidas. Por favor, abre un issue para discutir cambios importantes.
📄 Licencia
Este proyecto está bajo licencia MIT. Ver archivo LICENSE para más detalles.

⭐ ¿Te gustó este proyecto? ¡No olvides darle una estrella!
