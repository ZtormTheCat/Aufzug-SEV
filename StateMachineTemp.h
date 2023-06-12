#include <iostream>

using namespace std;
/*
Filthy ChatGPT rip
*/
class State {
public:
    virtual void performStateLogic() = 0;
    virtual State* transitionToNextState() = 0;
};

class State1 : public State {
public:
    void performStateLogic() override {
        cout << "Currently in STATE1. Transitioning to STATE2." << endl;
    }

    State* transitionToNextState() override {
        return new State2();
    }
};

class State2 : public State {
public:
    void performStateLogic() override {
        cout << "Currently in STATE2. Transitioning to STATE3." << endl;
    }

    State* transitionToNextState() override {
        return new State3();
    }
};

class State3 : public State {
public:
    void performStateLogic() override {
        cout << "Currently in STATE3. Transitioning to STATE4." << endl;
    }

    State* transitionToNextState() override {
        return new State4();
    }
};

class State4 : public State {
public:
    void performStateLogic() override {
        cout << "Currently in STATE4. Transitioning back to STATE1." << endl;
    }

    State* transitionToNextState() override {
        return new State1();
    }
};

int main() {
    State* currentState = new State1();

    while (true) {
        currentState->performStateLogic();
        State* nextState = currentState->transitionToNextState();
        
        // Delete the current state object
        delete currentState;
        
        // Break the loop if nextState is nullptr (termination condition)
        if (nextState == nullptr) {
            break;
        }
        
        currentState = nextState;
    }

    return 0;
}