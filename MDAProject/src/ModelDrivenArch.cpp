#include "ModelDrivenArch.hpp"
#include "Actions.hpp"


void StartState::open() {
        context->changeState(IDLE);
        op->storeCardData();
        //op->storePin();
        //op->storeId();
        //op->storeBalance();
}


void IdleState::login() {
        context->changeState(CHECKPIN);
        context->setAttempts(0);
}

void IdleState::loginFail() {
        op->incorrectIdMsg();
}


void CheckPinState::correctPin() {
        context->changeState(TEMP);
        op->displayMenu();
}

void CheckPinState::incorrectPin(int max) {
        int attempts = context->getAttempts();
        if (attempts >= max) {
                context->changeState(IDLE);
                //context->setAttempts(0); ???
                op->tooManyAttemptMsg();
        } else if (attempts < max) {
                context->setAttempts(++attempts);
                op->incorrectPinMsg();
        }
}

void CheckPinState::logout() {
        context->changeState(IDLE);
}


void ReadyState::balance() {
        op->displayBalance();
}

void ReadyState::lockFail() {
        op->incorrectPinMsg();
}

void ReadyState::lock() {
        context->changeState(LOCKED);
}

void ReadyState::suspend() {
        context->changeState(SUSPENDED);
}

void ReadyState::withdrawFail() {
        op->noFundMsg();
}

void ReadyState::withdraw() {
        context->changeState(TEMP);
        op->doWithdraw();
}

void ReadyState::deposit() {
        op->doDeposit();
}

void ReadyState::logout() {
        context->changeState(IDLE);
}


void OverdrawnState::logout() {
        context->changeState(IDLE);
}

void OverdrawnState::balance() {
        op->displayBalance();
}

void OverdrawnState::lockFail() {
        op->incorrectPinMsg();
}

void OverdrawnState::lock() {
        context->changeState(LOCKED);
}

void OverdrawnState::deposit() {
        context->changeState(TEMP);
        op->doDeposit();
}

void OverdrawnState::withdraw() {
        op->belowMinMsg();
}


void LockedState::unlock() {
        context->changeState(TEMP);
}

void LockedState::unlockFail() {
        op->incorrectPinMsg();
}


void SuspendedState::activate() {
        context->changeState(READY);
}

void SuspendedState::balance() {
        op->displayBalance();
}

void SuspendedState::close() {
        context->changeState(CLOSED);
}


void TempState::aboveMin() {
        context->changeState(READY);
}

void TempState::belowMin() {
        context->changeState(OVERDRAWN);
}

void TempState::withdrawBelowMin() {
        context->changeState(OVERDRAWN);
        op->penalty();
}


ModelDrivenArch::ModelDrivenArch(OutputProcessor *op) {
        StartState *ss = new StartState(this, op);
        IdleState *is = new IdleState(this, op);
        CheckPinState *cps = new CheckPinState(this, op);
        ReadyState *rs = new ReadyState(this, op);
        OverdrawnState *os = new OverdrawnState(this, op);
        LockedState *ls = new LockedState(this, op);
        SuspendedState *ss2 = new SuspendedState(this, op);
        ClosedState *cs = new ClosedState(this, op);
        TempState *ts = new TempState(this, op);

        states.push_back(ss);
        states.push_back(is);
        states.push_back(cps);
        states.push_back(rs);
        states.push_back(os);
        states.push_back(ls);
        states.push_back(ss2);
        states.push_back(cs);
        states.push_back(ts);
 
        current = states[0];
}

ModelDrivenArch::~ModelDrivenArch() {
        for (int i = 0; i < states.size(); ++i) {
                delete states[i];
        }
}

void ModelDrivenArch::changeState(StateEnum stateID) {
        switch (stateID) {
                case START:
                        current = states[0];
                        break;
                case IDLE:
                        current = states[1];
                        break;
                case CHECKPIN:
                        current = states[2];
                        break;
                case READY:
                        current = states[3];
                        break;
                case OVERDRAWN:
                        current = states[4];
                        break;
                case LOCKED:
                        current = states[5];
                        break;
                case SUSPENDED:
                        current = states[6];
                        break;
                case CLOSED:
                        current = states[7];
                        break;
                case TEMP:
                        current = states[8];
                        break;
                default:
                        break;
        }
}

