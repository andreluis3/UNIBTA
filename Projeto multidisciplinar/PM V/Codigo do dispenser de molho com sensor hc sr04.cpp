// Algoritmo do dispenser de molho com sensor HC-SR04


#include <Servo.h>

Servo servoMotor; // Objeto do servo motor

// Definição dos pinos do sensor HC-SR04
const int trigPin = 3; // Pino TRIG do sensor
const int echoPin = 4; // Pino ECHO do sensor
const int servoPin = 9; // Pino do servo motor

// Faixa de ativação do sensor (mínimo e máximo em cm)
const int distanciaMin = 5;
const int distanciaMax = 10;

void setup() {  
    servoMotor.attach(servoPin); // Define o pino do servo
    pinMode(trigPin, OUTPUT);    // Configura TRIG como saída
    pinMode(echoPin, INPUT);     // Configura ECHO como entrada
    servoMotor.write(0);         // Posição inicial do servo
    Serial.begin(9600);          // Inicializa a comunicação serial para testes
}

void loop() {   
    long duracao;
    int distancia;

    // Disparo do sinal ultrassônico
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Leitura do tempo de resposta
    duracao = pulseIn(echoPin, HIGH);

    // Cálculo da distância (em cm)
    distancia = duracao * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    // Aciona o servo motor somente se a distância estiver entre 5 e 10 cm
    if (distancia >= distanciaMin && distancia <= distanciaMax) { 
        servoMotor.write(90); // Move o servo para 90°
        delay(500); // Tempo para despejar o molho
        servoMotor.write(0);  // Retorna à posição inicial
        delay(1000); // Tempo para evitar acionamentos repetitivos
    }

    delay(100); // Pequeno delay para leituras mais estáveis
}
