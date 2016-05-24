#include "Arduino.h"
using namespace std;

const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;
const int allLEDs[] = {greenLEDPin, blueLEDPin, redLEDPin};

const int redSensorPin = A1;
const int greenSensorPin = A0;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

// lol I almost forgot that I have to declare functions before using them... silly c
void allOff() {
  int numberOfLEDs = sizeof(allLEDs) / sizeof(int);
  for (int i = 0; i < numberOfLEDs; i++) {
    digitalWrite(allLEDs[i], 0);
  }
}

void cycleLEDPin(int pin) {
  digitalWrite(pin, 100);
  delay(1000);
  allOff();
}

void diagnosticCheck() {
  cycleLEDPin(redLEDPin);
  cycleLEDPin(blueLEDPin);
  cycleLEDPin(greenLEDPin);
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

  delay(1000);
  redSensorVal = analogRead(redSensorPin);
  blueSensorVal = analogRead(blueSensorPin);
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

  Serial.print("\n\nMapped Sensor Values \nRed: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);

  digitalWrite(redLEDPin, redValue);
  digitalWrite(blueLEDPin, blueValue);
  digitalWrite(greenLEDPin, greenValue);
}
