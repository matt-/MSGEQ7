#include "MSGEQ7.h"

// Example to control WS2801-based RGB LED Modules in a strand or strip
// Written by Adafruit - MIT license
/*****************************************************************************/

// Constructor for use with arbitrary reset and strobe pins:
MSGEQ7::MSGEQ7(uint8_t resetPin, uint8_t strobePin) {

}

// Constructor for use with default reset and strobe: 
MSGEQ7::MSGEQ7(void) {
  resetPin = 5;
  strobePin = 4;
}

// Init spectrum analyzer
void MSGEQ7::begin(void) {
    // Setup pins to drive the spectrum analyzer. 
    pinMode(resetPin, OUTPUT);
    pinMode(strobePin, OUTPUT);
    
    digitalWrite(strobePin,LOW);
      delay(1);
    digitalWrite(resetPin,HIGH);
      delay(1);
    digitalWrite(strobePin,HIGH);
      delay(1);
    digitalWrite(strobePin,LOW);
      delay(1);
    digitalWrite(resetPin,LOW);
      delay(5);
}

void MSGEQ7::readSpectrum(void) {
  byte Band;
  for(Band=0;Band <7; Band++)
  {
    chanLeft[Band] = (analogRead(0) + analogRead(0) ) >>1; //Read twice and take the average by dividing by 2
    chanRight[Band] =  (analogRead(1) + analogRead(1) ) >>1;
    
    digitalWrite(strobePin,HIGH);
    digitalWrite(strobePin,LOW);     
  }
} 

