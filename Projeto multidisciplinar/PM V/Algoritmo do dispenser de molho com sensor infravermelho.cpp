//ALGORITMO CODIGO SERVO MOTOR DISPENSER DE MOLHO (sensor errado)

#include <Servo.h>

Servo servoMotor; // cria um objeto tipo servo

const int sensorPin = 2; // pino do sensor de obstáculo 
const int servoPin = 9;  // pino do servo motor 

void setup() {  
    servoMotor.attach(servoPin); // Define o pino do servo
    pinMode(sensorPin, INPUT);   // Configura o sensor como entrada
    servoMotor.write(0);         // Posição inicial do servo
}

void loop() {   
    int sensorState = digitalRead(sensorPin); // Lê o sensor    

    if (sensorState == HIGH) { // Se detectar obstáculo 
        servoMotor.write(90); // Ângulo que o servo motor vai girar
        delay(500); // Espera um pouco (se o molho estiver escorrendo devagar, aumentar esse delay)
        servoMotor.write(0); // Retorna à posição inicial 
        delay(1000); // Tempo para evitar acionamentos repetitivos
    }
}
