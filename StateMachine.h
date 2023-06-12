#ifndef _StateMachine_
#define _StateMachine_
/**
 * @brief Abstract Class as a Template for Elevator-States
 * 
 */
class State {
protected:
    UserLED* uLED; //< Object-Reference from UserLED to set LED's
    Motor* uMot; //< Object-Reference from Motor to set Motor-States
    UserButton* uBut; //< Object-Reference from UserButton to get Button-Values
    Counter* uCnt; //< Object-Reference from Counter to get Count-Values
    volatile int* currCntVal; //< Current Counter Value: Volatile Integer pointing to a Return-Value
    int strdCnt; //< Stored Counter Value
public:
/**
 * @brief Construct a new State:: State object
 * 
 * @param led Object of an exsiting UserLED-Instance
 * @param mot Object of an exsiting Motor-Instance
 * @param but Object of an exsiting UserButton-Instance
 * @param cnt Object of an exsiting Counter-Instance
 */
    State(UserLED* led, Motor* mot, UserButton* but,Counter* cnt);
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
  uint8_t currentFloor;
  
public:
    State0();
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

/*Nach oben*/
class State1 : public State {
public:
    State1();
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
public:
    State2();
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
public:
    State3();
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