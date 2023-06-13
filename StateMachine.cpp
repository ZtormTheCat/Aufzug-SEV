/*
    Author: Everyone
*/
#include "StateMachine.h"
#include "Def.h"
#include "Motor.h"
#include "UserLED.h"
#include "UserButton.h"
#include "ModCounter.h"
#include "HMI.h"

using namespace Def;

State0::State0(HMI* hmi, Motor* mot, ModCounter* cnt):
            uHMI(hmi),
            uMot(mot),
            uCnt(cnt),
            strdCnt(cnt->GetValue()),
            currCntVal(cnt->GetValue())
{};
void State0::performStateLogic()
{
  uHMI->printMessage(std::to_string(currCntVal));
    if(uHMI->getUserInput()=='F'){
          uCnt->Inc();
          currCntVal = uCnt->GetValue();
    }
    uHMI->controlLED(currCntVal);
    uMot->setMotorState((uint8_t)Still);
};

State* State0::transitionToNextState()
{
    if (uHMI->getUserInput()=='X'){
        return new State3(this->uHMI, this->uMot, this->uCnt);
    }

    if (currCntVal>strdCnt && uHMI->getUserInput()=='B'){
        strdCnt = currCntVal;
        return new State1(this->uHMI, this->uMot, this->uCnt);
    }
    else if(currCntVal<strdCnt && uHMI->getUserInput()=='B'){
        strdCnt = currCntVal;
        return new State2(this->uHMI, this->uMot, this->uCnt);
    }
    else {
      return nullptr;
    }
}

/*Nach oben*/
State1::State1(HMI* hmi, Motor* mot, ModCounter* cnt):
            uHMI(hmi),
            uMot(mot),
            uCnt(cnt)
{};
void State1::performStateLogic()
{
    uHMI->controlLED(Bin5);
    uMot->setMotorState(Rauf);
}

State* State1::transitionToNextState()
{
    if (uHMI->getUserInput()=='X'){
        return new State3(this->uHMI, this->uMot, this->uCnt);
    }
    if(uHMI->getUserInput()== 'S'){
        return new State0(this->uHMI, this->uMot, this->uCnt);
    }
    else{
      return nullptr;
    }
}
/*Nach Unten*/
State2::State2(HMI* hmi, Motor* mot, ModCounter* cnt):
            uHMI(hmi),
            uMot(mot),
            uCnt(cnt)
{}
void State2::performStateLogic()
{
    uHMI->controlLED(Bin6);
    uMot->setMotorState(Runter);
}

State* State2::transitionToNextState()
{
    if (uHMI->getUserInput()=='X'){
        return new State3(this->uHMI, this->uMot, this->uCnt);
    }
    if(uHMI->getUserInput()== 'S'){
        return new State0(this->uHMI, this->uMot, this->uCnt);
    }
    else{
        return nullptr;
    }

}
/*Störung*/
State3::State3(HMI* hmi, Motor* mot, ModCounter* cnt):
            uHMI(hmi),
            uMot(mot),
            uCnt(cnt)
{};
void State3::performStateLogic()
{
    uHMI->controlLED(Bin7);
    uMot->setMotorState(Still);
}

State* State3::transitionToNextState()
{
    if (uHMI->getUserInput()=='X'){
        return new State0(this->uHMI, this->uMot, this->uCnt);
    }
    else{
        return nullptr;
    }
}
/*
int startStateMachine() {
    State* currentState = new State0();

    while (true) {
        currentState->performStateLogic();
        State* nextState = currentState->transitionToNextState();

        // Delete the current state object
        delete currentState;

        // Break the loop if nextState is nullptr (termination condition)
        if (nextState == nullptr) { //TODO: Abbruchbedingung festlegen (optional)
            break;
        }

        currentState = nextState;
    }

    return 0;
}
*/
