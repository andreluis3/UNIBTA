#include <SevSeg.h>

SevSeg sevseg; // Instancia do display 7 segmentos

const int buttonPin = 2;       // botão com interrupt
const int greenLedPin = 8;     // LED verde
const int redLedPin = 9;       // LED vermelho

volatile bool stopCounting = false;
volatile int currentCount = 0;

unsigned long lastUpdate = 0;
const unsigned long interval = 333; // 3x mais rápido que 1 segundo = 333ms

void IRAM_ATTR handleButtonInterrupt() {
  stopCounting = true;
}

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonInterrupt, FALLING);

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  // Configura display 7 segmentos - ajuste conforme seu hardware
  byte numDigits = 2;
  byte digitPins[] = {2, 3};
  byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10}; // Ajuste para seus pinos
  bool resistorsOnSegments = false;
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  sevseg.refreshDisplay();

  if (!stopCounting) {
    unsigned long now = millis();
    if (now - lastUpdate >= interval) {
      lastUpdate = now;
      currentCount++;
      if (currentCount > 10) {
        currentCount = 1; // volta a contar de 1
      }
    }
  }

  sevseg.setNumber(currentCount, 0);

  if (stopCounting) {
    // Verifica se acertou o 10 segundos (contador parou em 10)
    if (currentCount == 10) {
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
    } else {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
    }
    // Para evitar múltiplas avaliações, espera aqui
    while(true) {
      sevseg.refreshDisplay();
      // Pode adicionar um reset com outro botão ou tempo depois
    }
  }
}
