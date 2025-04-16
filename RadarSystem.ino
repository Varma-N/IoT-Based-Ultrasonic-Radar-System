#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const int servoPin = 11;

// Servo setup
Servo myServo;

// LCD setup (I2C address 0x27 — adjust if needed)
Adafruit_LiquidCrystal lcd(0x27);

// Global variables
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
  
// Initialize the LCD
  lcd.begin(16, 2);              
  lcd.print("Radar System");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Sweep from 0° to 180°
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(10);
    measureDistance();
    displayInfo(pos);
    checkLED();
  }

  // Sweep back from 180° to 0°
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(10);
    measureDistance();
    displayInfo(pos);
    checkLED();
  }
}

void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void checkLED() {
  if (distance > 0 && distance < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void displayInfo(int angle) {
  // Serial output
  Serial.print("Position: ");
  Serial.print(angle);
  Serial.print(" degrees, Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("Dist:");
  lcd.print(distance);
  lcd.print("cm   "); // Extra spaces to clear old digits

  lcd.setCursor(0, 1);
  if (distance > 0 && distance < 100) {
    lcd.print("Detected ");
  } else {
    lcd.print("Clear    ");
  }
}
