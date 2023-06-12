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
        
        
        
        // Break the loop if nextState is nullptr (termination condition)
        if (nextState == nullptr) {
          continue;
        }
        
        // Delete the current state object
        delete currentState;
        
        currentState = nextState;
  }
}
