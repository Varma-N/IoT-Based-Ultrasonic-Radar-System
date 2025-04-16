# IoT-Based Ultrasonic Radar System

An Arduino Uno-based radar system using an ultrasonic sensor and servo motor to detect nearby objects and display the distance on an I2C 16x2 LCD.

## 🧠 Features

- Ultrasonic distance measurement (HC-SR04)
- Servo motor sweeps 0°–180° and back
- Object detection indication via LED
- Real-time distance and status shown on LCD
- Live data over Serial Monitor

## 🛠️ Hardware Used

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- I2C 16x2 LCD Display
- LED + Resistor
- Breadboard + Jumper wires

## 🔌 Pin Connections

| Component        | Arduino Pin |
|------------------|-------------|
| Trig (HC-SR04)   | 9           |
| Echo (HC-SR04)   | 10          |
| Servo Signal     | 11          |
| LED              | 13          |
| LCD (I2C)        | A4 (SDA), A5 (SCL) |

## 💻 Code

The full code is available in `RadarSystem.ino`.

## 📷 Preview
### Schematic View
![image](https://github.com/user-attachments/assets/13d37896-b366-4d6e-93b4-d45bf64c3a5e)
### Circuit View
![image](https://github.com/user-attachments/assets/3ca1ab05-9a50-4e9e-a08c-3752319dd302)


## 📄 License

MIT License
