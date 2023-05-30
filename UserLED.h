#include "GPIO.h"


#ifndef _USERLED_
#define _USERLED_
class UserLED
{
private:
    const uint32_t LEDPortAddr;
    uint16_t setPortStream;
    GPIO *LEDPort;
    void Init();

public:
    UserLED(uint32_t passPort);
    //~UserLED();
    void SetValue(uint8_t bit8Stream);
};
#endif