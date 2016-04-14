#ifndef _MODELDRIVENARCH_HPP
#define _MODELDRIVENARCH_HPP

#include <vector>
#include "Actions.hpp"

using namespace std;

typedef enum {
        START = 0,
        IDLE,
        CHECKPIN,
        READY,
        OVERDRAWN,
        LOCKED,
        SUSPENDED,
        CLOSED,
        TEMP
} StateEnum;

class ModelDrivenArch;

class State {
        protected:
                ModelDrivenArch *context;
                OutputProcessor *op;
        public:
                State(ModelDrivenArch *ctxt,
                                OutputProcessor *o): context(ctxt), op(o) {};
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
                virtual void withdrawBelowMin() {};
                virtual void deposit() {};
                virtual void lock() {};
                virtual void lockFail() {};
                virtual void unlock() {};
                virtual void unlockFail() {};
                virtual void suspend() {};
                virtual void activate() {};
                virtual void close() {};
};

class StartState: public State {
        public: 
                StartState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~StartState() {};

                virtual void open();
};

class IdleState: public State {
        public:
                IdleState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~IdleState() {};

                virtual void login();
                virtual void loginFail();
};

class CheckPinState: public State {
        public:
                CheckPinState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~CheckPinState() {};

                virtual void correctPin();
                virtual void incorrectPin(int max);
                virtual void logout();
};

class ReadyState: public State {
        public:
                ReadyState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~ReadyState() {};

                virtual void balance();
                virtual void lockFail();
                virtual void lock();
                virtual void suspend();
                virtual void withdrawFail();
                virtual void withdraw();
                virtual void deposit();
                virtual void logout();
};

class OverdrawnState: public State {
        public:
                OverdrawnState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~OverdrawnState() {};

                virtual void logout();
                virtual void balance();
                virtual void lockFail();
                virtual void lock();
                virtual void deposit();
                virtual void withdraw();
};

class LockedState: public State {
        public:
                LockedState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~LockedState() {};

                virtual void unlockFail();
                virtual void unlock();
};

class SuspendedState: public State {
        public:
                SuspendedState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~SuspendedState() {};

                virtual void balance();        
                virtual void close();
                virtual void activate();
};

class ClosedState: public State {
        public:        
                ClosedState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~ClosedState() {};
};

class TempState: public State {
        public:
                TempState(ModelDrivenArch *ctxt,
                                OutputProcessor *o): State(ctxt, o) {};
                virtual ~TempState() {};

                virtual void aboveMin();
                virtual void belowMin();
                virtual void withdrawBelowMin();
};


class ModelDrivenArch {
        private:
                vector<State *> states;
                State *current;
                int attempts;
        public:
                ModelDrivenArch(OutputProcessor *op);
                virtual ~ModelDrivenArch();

                void changeState(StateEnum stateID);

                void setAttempts(int a);
                int getAttempts();

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
                void withdrawBelowMin();
                void deposit();
                void lock();
                void lockFail();
                void unlock();
                void unlockFail();
                void suspend();
                void activate();
                void close();
};

#endif

