/*
  Gesture Control Car - Transmitter

  Hardware:
  - Arduino Nano/Uno
  - MPU6050 connected through I2C
  - HC-05 Bluetooth module

  MPU6050:
  VCC -> 5V or 3.3V according to module specification
  GND -> GND
  SDA -> A4 on Uno/Nano
  SCL -> A5 on Uno/Nano

  HC-05:
  TX -> Arduino software serial RX
  RX -> Arduino software serial TX through a voltage divider
*/

#include <Wire.h>
#include <SoftwareSerial.h>

const byte MPU6050_ADDR = 0x68;

// HC-05 connection:
// HC-05 TX -> D10 (Arduino RX)
// HC-05 RX -> D11 (Arduino TX through voltage divider)
SoftwareSerial bluetooth(10, 11);

int16_t accelX, accelY, accelZ;
char lastCommand = 'S';

const int FORWARD_THRESHOLD = 5000;
const int BACKWARD_THRESHOLD = -5000;
const int LEFT_THRESHOLD = -5000;
const int RIGHT_THRESHOLD = 5000;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  Wire.begin();

  // Wake up MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);

  Serial.println("Gesture transmitter ready.");
}

void readAccelerometer() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);

  accelX = (Wire.read() << 8) | Wire.read();
  accelY = (Wire.read() << 8) | Wire.read();
  accelZ = (Wire.read() << 8) | Wire.read();
}

char detectGesture() {
  // Adjust axis mapping and thresholds according to sensor orientation.
  if (accelY > FORWARD_THRESHOLD) {
    return 'F';
  }

  if (accelY < BACKWARD_THRESHOLD) {
    return 'B';
  }

  if (accelX < LEFT_THRESHOLD) {
    return 'L';
  }

  if (accelX > RIGHT_THRESHOLD) {
    return 'R';
  }

  return 'S';
}

void loop() {
  readAccelerometer();

  char command = detectGesture();

  // Send only when the command changes to reduce unnecessary traffic.
  if (command != lastCommand) {
    bluetooth.write(command);
    Serial.print("Command sent: ");
    Serial.println(command);
    lastCommand = command;
  }

  delay(100);
}
