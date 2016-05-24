#include "Arduino.h"
using namespace std;

class PhotoReceptor {
public:
  PhotoReceptor(int redPin, int greenPin, int bluePin) {
    this->photoGreenPin = greenPin;
    this->photoBluePin = bluePin;
    this->photoRedPin = redPin;
  };
  void allOff();
  void diagnosticCheck();
  void updateValues(int red, int blue, int green);
  void updateValues(int red, int blue, int green, bool log);

private:
  int photoRedPin = 0;
  int photoBluePin = 0;
  int photoGreenPin = 0;
  int allLEDs[];
  void cycleLEDPin(int pin);
};

void PhotoReceptor::allOff() {
  digitalWrite(photoRedPin, 0);
  digitalWrite(photoBluePin, 0);
  digitalWrite(photoGreenPin, 0);
}

void PhotoReceptor::diagnosticCheck() {
  cycleLEDPin(photoBluePin);
  cycleLEDPin(photoRedPin);
  cycleLEDPin(photoGreenPin);
}

void PhotoReceptor::updateValues(int red, int blue, int green) {
  digitalWrite(photoRedPin, red);
  digitalWrite(photoBluePin, blue);
  digitalWrite(photoGreenPin, green);
}

void PhotoReceptor::updateValues(int red, int blue, int green, bool log) {
  if (log == true) {
      Serial.print("\n\nMapped Sensor Values \nRed: ");
      Serial.print(red);
      Serial.print("\t Green: ");
      Serial.print(green);
      Serial.print("\t Blue: ");
      Serial.print(blue);
  }
  this->updateValues(red, blue, green);
}

void PhotoReceptor::cycleLEDPin(int pin) {
  digitalWrite(pin, 100);
  delay(1000);
  allOff();
}
