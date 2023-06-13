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
  HMI* uHMI = new HMI();
  ModCounter* uCnt = new ModCounter();
  Motor* uMot = new Motor();

  State* currentState = new State0(uHMI, uMot, uCnt);

  while(1){

    currentState->performStateLogic();
    State* nextState = currentState->transitionToNextState();

    if (nextState == nullptr) { // Do not override currentState, if transit-conditions are not met.
      continue;
    }
      
    delete currentState; // Delete the current state object
      
    currentState = nextState;
  }
}
