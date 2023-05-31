#include <iostream>
#include "Motor.h"

using namespace std;

Motor::Motor(){}

void Motor::setMotorState(uint8_t motorState)
{
    switch(motorState)
    {
        case 1:
            cout << "Fahre nach oben..." << endl;
            break;
        case 2:
            cout << "Fahre nach unten..." << endl;
            break;
        case 0:
            cout << "Fahre gleichzeitig nach oben und unten..." << endl;
            break;
        default:
            cout << "Übergabeparameter außerhalb gültigen Grenzen." << endl;
            break;
    }
    return;
}