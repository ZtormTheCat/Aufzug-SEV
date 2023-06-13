/*
    Author: Max Brehm
*/
#ifndef _MOTOR_
#define _MOTOR_
/**
 * @brief Plain Motor-Class. It only prints to terminal.
 *
 */
class Motor
{
public:
    /**
     * @brief Construct a new Motor object
     *
     */
    Motor();
    /**
     * @brief Set the Motor State object and prints the corrisponding text to the Terminal
     *
     * @param motorState
     * @return Nothing
     */
    void setMotorState(uint8_t motorState);
};
#endif
