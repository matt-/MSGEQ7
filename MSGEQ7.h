#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class MSGEQ7 {

 public:

  MSGEQ7(uint8_t resetPin, uint8_t strobePin); // Configurable pins
  MSGEQ7(void); // Empty constructor; init pins/strand length later
  void
    begin(void),
    readSpectrum(void);
  int
    resetPin, strobePin;
  uint16_t
    chanLeft[7], chanRight[7]; // Holds left and right audio values

  private:

   uint16_t
     numLEDs;    
};
