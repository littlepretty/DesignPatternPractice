#include <iostream>
#include "Actions.h"

typedef enum {
        START = 0,
        IDLE,
        CHECKPIN,
        READY,
        OVERDRAWN,
        LOCK,
        CLOSED
} StateEnum;


class State {
        private:
                ModelDrivenArch *context;
                OutputProcessor *op;
        public:
                virtual void open() {};
                virtual void login() {};
                virtual void loginFail() {};
                virtual void logout() {};
                virtual void incorrectPin(int max) {};
                virtual void correctPin() {};
                virtual void aboveMin() {};
                virtual void belowMin() {};
                virtual void balance() {};
                virtual void withdraw() {};
                virtual void withdrawFail() {};
                virtual void deposit() {};
                virtual void lock() {};
                virtual void lockFail() {};
                virtual void unlock() {};
                virtual void unlockFail() {};
                virtual void close() {};
}

class StartState: public State {

};

class IdleState: public State {

};

class CheckPinState: public State {

};

class ReadyState: public State {
};

class OverdrawnState: public State {
};

class LockState: public State {

};

class ClosedState: public State {

};


class ModelDrivenArch {
        private:
                vector<State *> states;
                State *current;
                int attempts;
        public:
                void changeState(StateEnum stateID);
                void open();
                void login();
                void loginFail();
                void logout();
                void incorrectPin(int max);
                void correctPin();
                void aboveMin();
                void belowMin();
                void balance();
                void withdraw();
                void withdrawFail();
                void deposit();
                void lock();
                void lockFail();
                void unlock();
                void unlockFail();
                void close();
};


