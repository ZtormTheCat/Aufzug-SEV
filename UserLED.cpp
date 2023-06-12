#include "GPIO.h"
#include "UserLED.h"

using namespace std;

UserLED::UserLED(uint32_t passPort): LEDPortAddr(passPort)
{ 
    this->Init();
}
void UserLED::Init()
{
    this->LEDPort = new GPIO(LEDPortAddr);
    this->LEDPort->configurePort(0xFFFF);
}

void UserLED::SetValue(uint8_t bit8Stream) 
{
    this->LEDPort->setPort((uint16_t)bit8Stream);
}