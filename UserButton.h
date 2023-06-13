//UserButton.h
#include "GPIO.h"
#include "Def.h"

#ifndef _USERBUTTON_
#define _USERBUTTON_

/**
* @brief Class to read the buttons using the GPIO-CLass
*/
class UserButton
{
private:
  unsigned long ButtonPortAddr; //< Is the port-adress of the button port
  GPIO *ButtonPort; //< Reference to GPIO-Class

  /**
  * @brief Creates a GPIO-Object and configures the port to an input-port
  *
  */
  void Init()
  
public:
  /**
  * @brief Construct a new UserButton object on port B
  *
  */
  UserButton()
  
  /**
  * @brief Read the input signal of the pin on the port that is at ButtonPortAddr
  *
  * @param pin The pin number of the input pin to read (value from 0 to 15)
  *
  * @return false if a LOW signal is noticed at this pin, true if it's a HIGH signal
  */
  bool readButtonState(uint16_t pin)
  
  /**
  * @brief Checks wether one of the user-input buttons or the sensor button is pressed
  * and returns a char if at least one is pressed.
  * @return 'S' for Sensor, 'X' for Start and Select, 'B' for Start and 'F' for Select.
  */
  char Pressed()
};
#endif
