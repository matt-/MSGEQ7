#include "MSGEQ7.h"

/*****************************************************************************
Example sketch for reading the MSGEQ7 Seven Band Spectrum Analyzer
*****************************************************************************/


MSGEQ7 analyzer = MSGEQ7();

// Optional: pass the pins for the Spectrum Analyzer 5 and 4 are default for the blitronics shield. 
//MSGEQ7 strip = MSGEQ7(5,4);

void setup() {
  Serial.begin(9600);
  analyzer.begin();
}


void loop() {

  analyzer.readSpectrum();
  //chanLeft = analyzer.chanLeft[0];
  Serial.println(analyzer.chanLeft[0]);
  delay(20);
}