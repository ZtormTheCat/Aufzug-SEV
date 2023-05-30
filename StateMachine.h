#include "Motor.h"

class State {
protected:
    volatile const uint8_t* currCntVal;
    volatile const uint8_t* strdCntVal;
    Motor *MotorLED;
    void Init();
public:
    State(uint8_t currCnt, uint8_t strdCnt);
    virtual void performStateLogic() = 0;
    virtual State* transitionToNextState() = 0;
};

/*Stillstand*/
class State0 : public State {
public:
    State0(uint8_t currCnt, uint8_t strdCnt);
    void performStateLogic() override;
    State* transitionToNextState() override;
};

/*Nach oben*/
class State1 : public State {
public:
    void performStateLogic() override;
    State* transitionToNextState() override;
};

/*Nach Unten*/
class State2 : public State {
public:
    void performStateLogic() override;
    State* transitionToNextState() override;
};

/*Störung*/
class State3 : public State {
public:
    void performStateLogic() override;
    State* transitionToNextState() override;
};