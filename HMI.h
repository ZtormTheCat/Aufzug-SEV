#include "UserLED.h"
#include "UserButton.h"
#include "Def.h"
#include "stdint.h"
#include "iostream"

#ifndef _HMI_
#define _HMI_

/**
* Class to directly control the GPIO Ports and Pins
*/
class HMI
{
  private:
    
    UserButton ButtonControl = UserButton();
    UserLED LEDControl = UserLED();
    //UserLED LEDControl();
public:
    
  void printMessage(std::string message){
      std::cout << message << std::endl;
    }
    
    char getUserInput(){
      while(1){
        std::string input = "";
        if(Def::op_mode::enable == 0){
          std::cin >> input;
        };
        if(input == "X" || input == "x" || ButtonControl.Pressed() == 'X')
        {
          printMessage("Error");
          return('X');
        }
        else if(input == "B" || ButtonControl.Pressed() == 'B'){
          printMessage("Start");
          return('B');
        }
        else if(input == "F" || ButtonControl.Pressed() == 'F'){
          printMessage("Select");
          return('F');
        }  
      }
    }
    
  void controlLED(uint8_t value) {
    LEDControl.SetValue(value);
  };
};
#endif


