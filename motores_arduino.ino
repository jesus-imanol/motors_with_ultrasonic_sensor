#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Configuración de la pantalla LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // La dirección 0x27 puede variar. Verifica la dirección de tu pantalla.

// Configuración del sensor de temperatura
const int PIN_SENSOR = 2;
OneWire oneWire(PIN_SENSOR);
DallasTemperature sensors(&oneWire);

const int echoPin = 4; 
const int trigPin = 5;

void setup() {
    // Configuración de los motores
    pinMode(10, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(3, OUTPUT);

    // Configuración del sensor ultrasónico
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
    // Iniciar sensor de temperatura
    sensors.begin();

    // Iniciar pantalla LCD
    lcd.begin(16, 2); // Iniciar LCD con 16 columnas y 2 filas
    lcd.backlight(); // Encender la luz de fondo
}

void loop() {
    // Leer distancia con el sensor ultrasónico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duracion = pulseIn(echoPin, HIGH);
    float distancia = duracion * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Leer temperatura
    sensors.requestTemperatures();
    float temperatura = sensors.getTempCByIndex(0);
    if (temperatura == -127.00) {
        Serial.println("Error: No se pudo leer la temperatura");
    } else {
        Serial.print("Temperatura: ");
        Serial.print(temperatura);
        Serial.println(" °C");

        // Mostrar temperatura en la pantalla LCD
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperatura);
        lcd.print(" C");
    }

    // Condiciones de movimiento y mensaje "Alto"
    if (distancia < 20) {
        Serial.println("Girando a la derecha...");
        digitalWrite(3, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(6, LOW);
        delay(1000);

        // Mostrar "Alto" en la pantalla LCD
        lcd.setCursor(0, 1);
        lcd.print("Alto          ");
    } else {
        Serial.println("Avanzando...");
        digitalWrite(3, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(6, HIGH);

        // Limpiar la línea 2 de la pantalla LCD
        lcd.setCursor(0, 1);
        lcd.print("                ");
    }

    delay(500); // Retraso para actualizar la pantalla LCD
}
