#include "GPIO.h"

#ifndef _USERLED_
#define _USERLED_
/**
 * @brief Class to manipulate LED's using the GPIO-Class
 */
class UserLED
{
private:
    const uint32_t LEDPortAddr; /**< Is initialized by passPort */
    GPIO *LEDPort;  /**< Reference to a GPIO-Class */
    /**
     * @brief Creates a GPIO-Object and configures the port to an Output-Port
     */
    void Init();

public:
    /**
     * @brief Construct a new User LED object.
     */
    UserLED();
    /**
     * @brief Set the Value object. For this implementation a 4-Bit-Strem ist excepted, where MSB is 0 because only 3 LED's are used.
     * @param bit8Stream gets cast into a uint16_t to fit the GPIO param exception
     */
    void SetValue(uint8_t bit8Stream);
};
#endif