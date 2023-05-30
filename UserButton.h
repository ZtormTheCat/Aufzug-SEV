//UserButton.h
#include "GPIO.h"

#ifndef _USERBUTTON_
#define _USERBUTTON_
class UserButton
{
private:
  unsigned long ButtonPortAddr;
  GPIO *ButtonPort;
  
  const int debounceDelay = 50;
  unsigned long debounceCounter;
  uint16_t buttonState;
  uint16_t lastButtonState;
  
public:
  //TODO: change address to PortB
  UserButton():ButtonPortAddr(0x40020000)
  {
    ButtonPort = new GPIO(ButtonPortAddr);
    //Init();
  }
  
  void Init()
  {
    ButtonPort->configurePort(0xFFFF);
  }
  
  bool readButtonState(uint16_t pin)
  {
    uint16_t readMask = 0x01 << pin;
    return (bool)(ButtonPort->getPort() & readMask);
  }
  
  
  char Pressed()
  {
    //check current state of the user-input
    bool StartButton  = readButtonState(9); //TODO: change to needed pin number
    bool SelectButton = readButtonState(10); //TODO: change to needed pin number
    //bool SensorButton = readButtonState(10);
    
    if      (StartButton && SelectButton)
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
