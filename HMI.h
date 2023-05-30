#include "UserLED.h"
#include "UserButton.h"
#include "Def.h"
#include <Windows.h>

#ifndef _HMI_
#define _HMI_

/**
* Class to directly control the GPIO Ports and Pins
*/
class HMI
{
  private:
    
    UserButton ButtonControl = UserButton();
    //UserLED LEDControl = UserLED();
    UserLED LEDControl();
public:
    
    void printMessage(string message){
    cout << message << endl;
    }
    
    char getUserInput(){
      while(1){
        if((GetKeyState('X') & 0x8000) || ButtonControl.Pressed() == 'X')
        {
          printMessage("Error");
        }
        else if((GetKeyState('B') & 0x8000) || ButtonControl.Pressed() == 'B'){
          printMessage("Start");
        }
        else if((GetKeyState('F') & 0x8000) || ButtonControl.Pressed() == 'F'){
          printMessage("Select");
        }  
      }
    }
};
#endif


