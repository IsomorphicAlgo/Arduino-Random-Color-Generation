// RGB Test 

/*The purpose of this sketch is to practice generating random variables
  and using them to control an RGB LED and perpetually generate new colors.
  This effectively allows the generation of 16 million color combinations.

  This project was created using the following:
  Software
    Arduino IDE 2.3.2
  Hardware
    Arduino Hero Uno
    Breadboard
    x4 wires
    RGB LED
    330 resistors 
*/

// used to allow seamless hero com
#include "Arduino.h"

// initialize pin variables
const byte BPin = 9; // Orange Wire controlling the blue pin
const byte GPin = 10; // Yellow Wire controlling the green pin
const byte RPin = 11; // White Wire controlling the red pin

// create function to send the brightness levels to the pin on the Hero board
void displayColor(
  byte BLum,
  byte GLum,
  byte RLum
) {
  analogWrite(BPin, BLum);
  analogWrite(GPin, GLum);
  analogWrite(RPin, RLum);
}

// initialize pin control and Serial for printing 
void setup() {
  pinMode(BPin, OUTPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  Serial.begin(9600);
}

// Below we create our random number generators
int genRanLum(){
  int randLum = random(0, 255);
  return randLum;
}

int genRanPin() {
  int randPin = random(0, 3);
  return randPin;
}

int genRanDirection() {
  return random(0, 2);  // Returns 0 or 1
}

// Initialize our individual pin light level variables
int BLum = 0;
int GLum = 0;
int RLum = 0;

// Initialize pin info variables
const int numPins = 3; // number of pins to choose from
const byte pinNums[numPins] = {11, 10, 9};

void loop() {
  // generate our random objects
  int randLum = genRanLum();
  int randPin = genRanPin();
  int randDirection = genRanDirection(); 
  int targetLum;
  byte chosenPin = pinNums[randPin];

  //Serial.println(randPin);
  //Serial.println(BLum);
  //Serial.println(GLum);
  //Serial.println(RLum);
  
  // logic through which pin it is, whether or not we are decreasing, 
  // and begin altering the appropriate pin to the desired random level.
  // Once finished the loop with start the process again
  if (chosenPin == 11) { 
    if (randDirection == 0) {
      targetLum = BLum - randLum;  // Change for decrease 
    } else {
      targetLum = BLum + randLum;
    }
    if (targetLum > 255) { 
      targetLum = 255;
    } else if (targetLum < 0) {
      targetLum = 0; 
    }
    while (BLum != targetLum) {
      if (BLum < targetLum) {
        BLum++;
      } else {
        BLum--;
      }
      displayColor(BLum, GLum, RLum);
      delay(5);
    }
  }
  if (chosenPin == 10) { 
    if (randDirection == 0) {
      targetLum = GLum - randLum;  // Change for decrease 
    } else {
      targetLum = GLum + randLum;
    }
    if (targetLum > 255) { 
      targetLum = 255;
    } else if (targetLum < 0) {
      targetLum = 0; 
    }
    while (GLum != targetLum) {
      if (GLum < targetLum) {
        GLum++;
      } else {
        GLum--;
      }
      displayColor(BLum, GLum, RLum);
      delay(5);
    }
  }
  if (chosenPin == 9) { 
    if (randDirection == 0) {
      targetLum = RLum - randLum;  // Change for decrease 
    } else {
      targetLum = RLum + randLum;
    }
    if (targetLum > 255) { 
      targetLum = 255;
    } else if (targetLum < 0) {
      targetLum = 0; 
    }
    while (RLum != targetLum) {
      if (RLum < targetLum) {
        RLum++;
      } else {
        RLum--;
      }
      displayColor(BLum, GLum, RLum);
      delay(5);
    }
  }
}
