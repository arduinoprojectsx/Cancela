#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo meuServo;

const int ledVerde = 4;
const int ledVermelho = 5;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  meuServo.attach(3);

  // Estado inicial: fechado
  meuServo.write(90);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  Serial.println("Aproxime um cartao...");
}

void loop() {
  // Verifica se há cartão
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Lê o cartão
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("Cartao detectado!");

  // Abre
  meuServo.write(180);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledVerde, HIGH);

  delay(3000); // aberto por 3 segundos

  // Fecha
  meuServo.write(90);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);

  mfrc522.PICC_HaltA();
}
