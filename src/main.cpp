#include "Arduino.h"
using namespace std;

const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A1;
const int greenSensorPin = A0;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

void allOff() {
  digitalWrite(redLEDPin, 0);
  digitalWrite(blueLEDPin, 0);
  digitalWrite(greenLEDPin, 0);
}

void cycleLEDPin(int pin) {
  digitalWrite(pin, 100);
}

void diagnosticCheck() {
  cycleLEDPin(redLEDPin);
  delay(1000);
  allOff();

  cycleLEDPin(blueLEDPin);
  delay(1000);
  allOff();

  cycleLEDPin(greenLEDPin);
  delay(1000);
  allOff();
}

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  allOff();
  diagnosticCheck();
}

void loop() {

  redSensorVal = analogRead(redSensorPin);
  delay(1);
  blueSensorVal = analogRead(blueSensorPin);
  delay(1);
  greenSensorVal = analogRead(greenSensorPin);

  // Serial.print("\n\nRaw Sensor Values \nRed: ");
  // Serial.print(redSensorVal);
  // Serial.print("\t Green: ");
  // Serial.print(greenSensorVal);
  // Serial.print("\t Blue: ");
  // Serial.print(blueSensorVal);

  redValue = redSensorVal/4;
  blueValue = blueSensorVal/4;
  greenValue = greenSensorVal/4;

  // Serial.print("\n\nMapped Sensor Values \nRed: ");
  // Serial.print(redValue);
  // Serial.print("\t Green: ");
  // Serial.print(greenValue);
  // Serial.print("\t Blue: ");
  // Serial.print(blueValue);

  digitalWrite(redLEDPin, redValue);
  digitalWrite(blueLEDPin, blueValue);
  digitalWrite(greenLEDPin, greenValue);
}
