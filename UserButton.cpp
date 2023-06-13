/*
    Author: Dominik Podsada
*/
#include "UserButton.h"

UserButton::UserButton():ButtonPortAddr(Def::enumPort::PortB)
{
    Init();
}

void UserButton::Init()
{
    ButtonPort = new GPIO(ButtonPortAddr);
    ButtonPort->configurePort(0xFFFF);
}

bool UserButton::readButtonState(uint16_t pin)
{
    uint16_t readMask = 0x01 << pin;
    return (bool)(ButtonPort->getPort() & readMask);
}

char UserButton::Pressed()
{
    //check current state of the user-input
    bool StartButton  = readButtonState(3);
    bool SelectButton = readButtonState(5);
    bool Sensor       = readButtonState(10);

    if      (Sensor)
        return 'S';
    else if (StartButton && SelectButton)
        return 'X';
    else if (StartButton && !SelectButton)
        return 'B';
    else if (!StartButton && SelectButton)
        return 'F';
    else
        return 0;
}
