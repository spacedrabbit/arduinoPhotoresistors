#include "Arduino.h"
#include "PhotoReceptor.cpp"
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

PhotoReceptor pr = PhotoReceptor(redLEDPin, greenLEDPin, blueLEDPin);

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);

  pr.allOff();
  pr.diagnosticCheck();
}

void loop() {

  delay(1000);
  redSensorVal = analogRead(redSensorPin);
  blueSensorVal = analogRead(blueSensorPin);
  greenSensorVal = analogRead(greenSensorPin);

  redValue = redSensorVal/4;
  blueValue = blueSensorVal/4;
  greenValue = greenSensorVal/4;

  pr.updateValues(redValue, blueValue, greenValue, true);
}
