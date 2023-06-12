#include "Motor.h"
#include "ModCounter.h"

class State {
protected:
    State *nextState;
public:
    State();
    virtual void performStateLogic() = 0;
    virtual State* transitionToNextState() = 0;
};

/*Stillstand*/
class State0 : public State {
protected:
  uint8_t currentFloor;
  
public:
  State0(ModCounter* modCounter) : currentFloor(modCounter->GetValue()) {};
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