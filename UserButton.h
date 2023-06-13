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
  {
    ButtonPort = new GPIO(ButtonPortAddr);
    ButtonPort->configurePort(0xFFFF);
  }
  
public:
  /**
  * @brief Construct a new UserButton object on port B
  *
  */
  UserButton():ButtonPortAddr(Def::enumPort::PortB)
  {
    Init();
  }
  
  /**
  * @brief Read the input signal of the pin on the port that is at ButtonPortAddr
  *
  * @param pin The pin number of the input pin to read (value from 0 to 15)
  */
  bool readButtonState(uint16_t pin)
  {
    uint16_t readMask = 0x01 << pin;
    return (bool)(ButtonPort->getPort() & readMask);
  }
  
  /**
  * @brief Checks wether one of the user-input buttons or the sensor button is pressed
  * and returns a char if at least one is pressed.
  * 'S' for Sensor, 'X' for Start and Select, 'B' for Start and 'F' for Select.
  */
  char Pressed()
  {
    //check current state of the user-input
    bool StartButton  = readButtonState(3);
    bool SelectButton = readButtonState(5);
    bool Sensor       = readButtonState(10);
    //bool SensorButton = readButtonState(10);
    
    if      (Sensor)
      return 'S';
    else if (StartButton && SelectButton)
      return 'X';
    else if (StartButton && !SelectButton)
      return 'B';
    else if (!StartButton && SelectButton)
      return 'F';
    else
      return 0;
  }
};
#endif
