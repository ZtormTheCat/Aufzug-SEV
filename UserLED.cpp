//UserLED.cpp
#include "UserLED.h"

using namespace std;

UserLED::UserLED(uint32_t passPort): LEDPortAddr(passPort), setPortStream(0)
{ 
    this->Init();
}
void UserLED::Init()
{
    this->LEDPort = new GPIO(LEDPortAddr);
    this->LEDPort->configurePort(0xFFFF);
}

/*
Expects 4-Bit integer, passes Port a 16-Bit-Stream.
*/
void UserLED::SetValue(uint8_t bit8Stream) 
{
    setPortStream = 0;
    setPortStream = (uint16_t)bit8Stream << 8;

    this->LEDPort->setPort(setPortStream);
}