#include "statemachine.h"
#include "Def.h"

using namespace Def;

State::State(uint8_t currCnt, uint8_t strdCnt): currCntVal((const volatile uint8_t*) currCnt),
                                                strdCntVal((const volatile uint8_t*) strdCnt)
{
    Init();
}

void State::Init()
{
    Motor *MotorLED = new Motor();
}
/*Stillstand*/
void State0::performStateLogic()
{
    switch (currCntVal)
    {
    case 1:
        MotorLED->motorStatus(0b0001);
        break;
    case 2:
        MotorLED->motorStatus(0b0010);
        break;
    case 3:
        MotorLED->motorStatus(0b0011);
        break;
    case 4:
        MotorLED->motorStatus(0b0100);
        break;
    default:
        break;
    }
}

State* State0::transitionToNextState()
{
    if nach_oben:
        return new State1();
    if störung:
        return new State3();
}

/*Nach oben*/
void State1::performStateLogic()
{
    MotorLED->motorStatus(0b0101);
}

State* State1::transitionToNextState()
{
    if angekommen:
        return new State0();
    if störung:
        return new State3();
}
/*Nach Unten*/
void State2::performStateLogic()
{
    MotorLED->motorStatus(0b0110);
}

State* State2::transitionToNextState()
{
    if angekommen:
        return new State0();
    if störung:
        return new State3();
}
/*Störung*/
void State3::performStateLogic()
{
    MotorLED->motorStatus(0b0111);
}

State* State3::transitionToNextState()
{
    return new State0();
}
