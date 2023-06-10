#include "StateMachine.h"
#include "Def.h"
#include "Motor.h"
#include "UserLED.h"
#include "UserButton.h"
#include "Counter.h"

using namespace Def;

State::State(UserLED* led, Motor* mot, UserButton* but, Counter* cnt):
            uLED(led),
            uMot(mot),
            uBut(but),
            uCnt(cnt),
            currCntVal((volatile int*)cnt->GetValue())
{}

void State0::performStateLogic()
{
    strdCnt = *currCntVal;
    uLED->SetValue((uint8_t)*currCntVal);
    uMot->setMotorState((uint8_t)Still);
};

State* State0::transitionToNextState()
{
    if (*currCntVal>strdCnt && uBut->Pressed()=='B'){
        return new State1();
    }
    else if(*currCntVal<strdCnt && uBut->Pressed()=='B'){
        return new State2();
    }

    if (uBut->Pressed()=='X'){
        return new State3();
    }
}

/*Nach oben*/
void State1::performStateLogic()
{
    uLED->SetValue(Bin5);
    uMot->setMotorState(Rauf);
}

State* State1::transitionToNextState()
{
    if(uBut->Pressed()== 'S'){
        return new State0();
    }
    if (uBut->Pressed()=='X'){
        return new State3();
    }
}
/*Nach Unten*/
void State2::performStateLogic()
{
    uLED->SetValue(Bin6);
    uMot->setMotorState(0b0110);
}

State* State2::transitionToNextState()
{
    if(uBut->Pressed()== 'S'){
        return new State0();
    }
    if (uBut->Pressed()=='X'){
        return new State3();
    }
}
/*Störung*/
void State3::performStateLogic()
{
    uLED->SetValue(Bin7);
    uMot->setMotorState(Still);
}

State* State3::transitionToNextState()
{
    if (uBut->Pressed()=='X'){
        return new State0();
    }
}

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