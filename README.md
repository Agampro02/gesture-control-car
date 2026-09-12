# 🚗 Gesture Control Car

A gesture-controlled robotic car using Arduino, MPU6050, HC-05 Bluetooth communication, and an L298N motor driver.

## Overview

This project allows a user to control a robotic car by tilting a hand-mounted MPU6050 sensor. The transmitter Arduino reads the hand gesture and sends a command through Bluetooth. The receiver Arduino interprets the command and drives the motors through the L298N motor driver.

## Features

- Forward, backward, left, and right movement
- Stop command
- Gesture-based human-machine interaction
- Arduino-based embedded control
- Bluetooth wireless communication
- Simple and expandable robotics platform

## Hardware

### Transmitter

- Arduino Nano or Uno
- MPU6050 sensor
- HC-05 Bluetooth module
- Jumper wires
- Power source

### Receiver

- Arduino Uno or Nano
- HC-05 Bluetooth module
- L298N motor driver
- 2 DC geared motors
- Robotic car chassis
- Battery pack
- Jumper wires

## Software

- Arduino IDE
- Arduino C/C++
- Wire library

## System Architecture

```text
Hand Tilt
   ↓
MPU6050 Sensor
   ↓
Transmitter Arduino
   ↓
HC-05 Bluetooth
   ↓
Receiver HC-05
   ↓
Receiver Arduino
   ↓
L298N Motor Driver
   ↓
DC Motors
```

## Gesture Mapping

| Gesture | Command | Car Action |
|---|---|---|
| Tilt forward | F | Forward |
| Tilt backward | B | Backward |
| Tilt left | L | Left |
| Tilt right | R | Right |
| Neutral position | S | Stop |

## Repository Structure

```text
gesture-control-car/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   ├── transmitter/
│   │   └── transmitter.ino
│   └── receiver/
│       └── receiver.ino
└── docs/
    └── circuit-connections.md
```

## Setup

1. Install Arduino IDE.
2. Connect the MPU6050 to the transmitter Arduino.
3. Connect the transmitter HC-05 to the transmitter Arduino.
4. Connect the receiver HC-05 to the receiver Arduino.
5. Connect the receiver Arduino to the L298N motor driver.
6. Connect the motors to the L298N output terminals.
7. Pair the HC-05 Bluetooth modules.
8. Upload `transmitter.ino` to the transmitter board.
9. Upload `receiver.ino` to the receiver board.
10. Power the circuit and test the gestures.

## Important Bluetooth Note

For a typical HC-05 setup, one module should be configured as master and the other as slave, or the modules should be paired according to their firmware configuration. The serial communication speed used in this project is 9600 baud.

Use a voltage divider or suitable level shifting when connecting a 5V Arduino TX signal to the HC-05 RX pin.

## Safety Notes

- Do not power the motors directly from the Arduino 5V pin.
- Use a separate suitable battery supply for the motors.
- Connect the grounds of the Arduino, motor driver, and communication circuit together.
- Remove power before changing wiring.
- Test the wheels off the ground initially.

## Future Scope

- Add obstacle detection using an ultrasonic sensor
- Add Wi-Fi or mobile-app control
- Add voice-control support
- Improve gesture classification
- Add autonomous navigation
- Add battery monitoring
- Add speed control using PWM

## Author

**Agam Tiwari**

B.Tech Student | IoT Enthusiast | Robotics and Embedded Systems Learner

If this project helps you, please ⭐ star the repository.
