#include "GPIO.h"
#include "UserButton.h"
#include "Counter.h"
#include "ModCounter.h"
#include "UserLED.h"
#include "Motor.h"
#include "HMI.h"
#include "Def.h"
#include "StateMachine.h"
#include <iostream>

using namespace std;

int main()
{
  UserLED* uLed = new UserLED();
  UserButton* uBut = new UserButton();
  Counter* uCnt = new Counter();
  Motor* uMot = new Motor();

  State* currentState = new State0(uLed, uMot, uBut, uCnt);

  while(1){
    currentState->performStateLogic();
        State* nextState = currentState->transitionToNextState();
        
        // Delete the current state object
        delete currentState;
        
        // Break the loop if nextState is nullptr (termination condition)
        if (nextState == nullptr) {
            break;
        }
        
        currentState = nextState;
  }
}
