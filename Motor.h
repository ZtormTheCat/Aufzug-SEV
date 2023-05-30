#include <iostream>
#include "UserLED.h"

using namespace std;

#ifndef _MOTOR_
#define _MOTOR_
class Motor
{
private:
    UserLED *DispLED;

public:
    Motor();
    void setMotorState(uint8_t motorState);
};
#endif