#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);

const int IN1 = 7;
const int IN2 = 8;
const int ENA = 5;
const int IN3 = 4;
const int IN4 = 12;
const int ENB = 11;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  if (BT.available()) {
    char command = BT.read();
    switch(command) {
      case 'F':
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        break;
      case 'B':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        break;
      case 'L':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        break;
      case 'R':
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        break;
      case 'S':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      default:
        Serial.println("Invalid command received!");
        break;
    }
  }
}
