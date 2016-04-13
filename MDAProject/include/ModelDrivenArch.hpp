#ifndef _MODELDRIVENARCH_HPP
#define _MODELDRIVENARCH_HPP

#include "Actions.h"

typedef enum {
        START = 0,
        IDLE,
        CHECKPIN,
        READY,
        OVERDRAWN,
        LOCKED,
        CLOSED,
        TEMP
} StateEnum;


class State {
        private:
                ModelDrivenArch *context;
                OutputProcessor *op;
        public:
                State(ModelDrivenArch *ctxt, OutputProcessor *o);
                virtual ~State() {};

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
};

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

class LockedState: public State {

};

class ClosedState: public State {

};

class TempState: public State {

};


class ModelDrivenArch {
        private:
                vector<State *> states;
                State *current;
                int attempts;
        public:
                ModelDrivenArch();
                virtual ~ModelDrivenArch();

                void changeState(StateEnum stateID);

                void setAttempts(int a) {
                        attempts = a;
                };
                int getAttempts() {
                        return attempts;
                };

                void open() {
                        current->open();
                };
                void login() {
                        current->login();
                };
                void loginFail() {
                        current->loginFail();
                };
                void logout() {
                        current->logout();
                };
                void incorrectPin(int max) {
                        current->incorrectPin(max);
                };
                void correctPin() {
                        current->correctPin();
                };
                void aboveMin() {
                        current->aboveMin();
                };
                void belowMin() {
                        current->belowMin();
                };
                void balance() {
                        current->balance();
                };
                void withdraw() {
                        current->withdraw();
                };
                void withdrawFail() {
                        current->withdrawFail();
                };
                void deposit() {
                        current->deposit();
                };
                void lock() {
                        current->lock();
                };
                void lockFail() {
                        current->lockFail();
                };
                void unlock() {
                        current->unlock();
                };
                void unlockFail() {
                        current->unlockFail();
                };
                void close() {
                        current->close();
                };
};

#endif

