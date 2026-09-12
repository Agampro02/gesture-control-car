# Circuit Connection Table

## 1. Transmitter: MPU6050 to Arduino Uno/Nano

| MPU6050 Pin | Arduino Uno/Nano Pin | Description |
|---|---|---|
| VCC | 5V or 3.3V* | Power |
| GND | GND | Ground |
| SDA | A4 | I2C data |
| SCL | A5 | I2C clock |

*Use the voltage recommended by your MPU6050 breakout board.

## 2. Transmitter: HC-05 to Arduino

| HC-05 Pin | Arduino Pin | Description |
|---|---|---|
| VCC | 5V | Module power input, according to breakout board |
| GND | GND | Common ground |
| TXD | D10 | SoftwareSerial receive |
| RXD | D11 through voltage divider | SoftwareSerial transmit |

## 3. Receiver: HC-05 to Arduino

| HC-05 Pin | Arduino Pin | Description |
|---|---|---|
| VCC | 5V | Module power input, according to breakout board |
| GND | GND | Common ground |
| TXD | D10 | SoftwareSerial receive |
| RXD | D11 through voltage divider | SoftwareSerial transmit |

## 4. Receiver: Arduino to L298N

| L298N Pin | Arduino Pin | Function |
|---|---|---|
| ENA | D5 | Motor A speed control |
| IN1 | D2 | Motor A direction 1 |
| IN2 | D3 | Motor A direction 2 |
| IN3 | D4 | Motor B direction 1 |
| IN4 | D7 | Motor B direction 2 |
| ENB | D6 | Motor B speed control |
| GND | GND | Common ground |

## 5. L298N to Motors and Battery

| L298N Terminal | Connection |
|---|---|
| OUT1 | Left motor terminal 1 |
| OUT2 | Left motor terminal 2 |
| OUT3 | Right motor terminal 1 |
| OUT4 | Right motor terminal 2 |
| 12V/VMS | Positive motor battery terminal |
| GND | Negative motor battery terminal and Arduino GND |

## Important Notes

- Remove the ENA/ENB jumpers if PWM speed control is used and connect ENA/ENB to the Arduino PWM pins.
- Motor direction may be reversed depending on motor wiring. Swap a motor's two wires if needed.
- Use a common ground between the Arduino and L298N.
- Do not power motors from the Arduino 5V output.
- HC-05 RX generally requires a voltage divider when driven by a 5V Arduino TX pin.
- The exact wiring must be checked against the specific modules used in the physical project.
