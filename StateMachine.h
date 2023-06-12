#include "UserLED.h"
#include "UserButton.h"
#include "Motor.h"
#include "ModCounter.h"
#include "HMI.h"


#ifndef _StateMachine_
#define _StateMachine_
/**
 * @brief Abstract Class as a Template for Elevator-States
 * 
 */
class State {
public:
/**
 * @brief Construct a new State:: State object
 * 
 * @param led Object of an exsiting UserLED-Instance
 * @param mot Object of an exsiting Motor-Instance
 * @param but Object of an exsiting UserButton-Instance
 * @param cnt Object of an exsiting Counter-Instance
 */
    /**
     * @brief Executes State-Behavior
     * 
     */
    virtual void performStateLogic() = 0;
    /**
     * @brief Condition-Check to transit to next State
     * 
     * @return State* 
     */
    virtual State* transitionToNextState() = 0;
};

/*Stillstand*/
class State0 : public State {
    protected:
    HMI* uHMI;
    Motor* uMot; //< Object-Reference from Motor to set Motor-States
    ModCounter* uCnt; //< Object-Reference from Counter to get Count-Values
    int currCntVal; //< Current Counter Value: Volatile Integer pointing to a Return-Value
    int strdCnt; //< Stored Counter Value
public:
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State0(HMI* hmi, Motor* mot, ModCounter* cnt);
    void performStateLogic() override;
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State* transitionToNextState() override;
};

/*Nach oben*/
class State1 : public State {
protected:
    HMI* uHMI;
    Motor* uMot; //< Object-Reference from Motor to set Motor-States
    ModCounter* uCnt; //< Object-Reference from Counter to get Count-Values
    volatile int* currCntVal; //< Current Counter Value: Volatile Integer pointing to a Return-Value
    int strdCnt; //< Stored Counter Value
public:
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State1(HMI* hmi, Motor* mot, ModCounter* cnt);
    /**
     * @brief Override for Base-Class: State
     * 
     */
    void performStateLogic() override;
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State* transitionToNextState() override;
};

/*Nach Unten*/
class State2 : public State {
protected:
    HMI* uHMI;
    Motor* uMot; //< Object-Reference from Motor to set Motor-States
    ModCounter* uCnt; //< Object-Reference from Counter to get Count-Values
    volatile int* currCntVal; //< Current Counter Value: Volatile Integer pointing to a Return-Value
    int strdCnt; //< Stored Counter Value
public:
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State2(HMI* hmi, Motor* mot, ModCounter* cnt);
    /**
     * @brief Override for Base-Class: State
     * 
     */
    void performStateLogic() override;
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State* transitionToNextState() override;
};

/*Störung*/
class State3 : public State {
protected:
    HMI* uHMI;
    Motor* uMot; //< Object-Reference from Motor to set Motor-States
    ModCounter* uCnt; //< Object-Reference from Counter to get Count-Values
    volatile int* currCntVal; //< Current Counter Value: Volatile Integer pointing to a Return-Value
    int strdCnt; //< Stored Counter Value
public:
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State3(HMI*, Motor* mot, ModCounter* cnt);
    /**
     * @brief Override for Base-Class: State
     * 
     */
    void performStateLogic() override;
    /**
     * @brief Override for Base-Class: State
     * 
     */
    State* transitionToNextState() override;
};
#endif