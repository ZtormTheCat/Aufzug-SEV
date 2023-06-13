/*
    Author: Tim Göhringer
*/
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

    UserButton ButtonControl = UserButton(); /**< Reference to UserButton-Class*/
    UserLED LEDControl = UserLED(); /**<  Reference to UserLED-Class*/
public:
  /**
  * @brief Print desired message to console
  * @param message message to be output
  */
  void printMessage(std::string message){
      std::cout << message << std::endl;
    }

  /**
  * @brief Get the user input from either keyboard or HW Buttons
  * @return The user input char
  */
  char getUserInput(){
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
    else if (input == "S" || ButtonControl.Pressed() == 'S'){
      printMessage("Sensor");
      return('S');
    }
  }

  /**
  * @brief sets the LEDs with the given mask in value
  * @param value a mask where the 3 LSB show the 3 LED states
  */
  void controlLED(int value) {
    LEDControl.SetValue(value);
  };
};
#endif


