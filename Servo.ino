#include <Servo.h>

Servo meuServo;

const int pinoServo = 3;
const int ledVerde = 4;
const int ledVermelho = 5;

void setup() {
  meuServo.attach(pinoServo);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Inicia fechado
  meuServo.write(90);

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
}

void loop() {
  // Abre (180°)
  meuServo.write(180);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);

  delay(1000);

  // Fecha (90°)
  meuServo.write(90);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  delay(1000);
}
