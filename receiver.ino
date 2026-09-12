/*
  Gesture Control Car - Receiver

  Hardware:
  - Arduino Uno/Nano
  - HC-05 Bluetooth module
  - L298N motor driver
  - Two DC motors

  HC-05:
  TX -> D10 (Arduino software serial RX)
  RX -> D11 (Arduino software serial TX through a voltage divider)

  L298N:
  ENA -> D5
  IN1 -> D2
  IN2 -> D3
  IN3 -> D4
  IN4 -> D7
  ENB -> D6
*/

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11);

const int ENA = 5;
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 7;
const int ENB = 6;

const int MOTOR_SPEED = 180;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  stopCar();

  Serial.println("Gesture receiver ready.");
}

void setMotorSpeed(int speedA, int speedB) {
  analogWrite(ENA, constrain(speedA, 0, 255));
  analogWrite(ENB, constrain(speedB, 0, 255));
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setMotorSpeed(MOTOR_SPEED, MOTOR_SPEED);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  setMotorSpeed(0, 0);
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      moveForward();
      break;

    case 'B':
      moveBackward();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
    default:
      stopCar();
      break;
  }
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    Serial.print("Command received: ");
    Serial.println(command);

    executeCommand(command);
  }
}
