#include "ModelDrivenArch.hpp"
#include "Actions.hpp"


State::State(ModelDrivenArchi *ctxt, OutputProcessor *o): context(ctxt), op(o) {
}

void StartState::open() {
        context->changeState(IDLE);
        op->storePin();
        op->storeId();
        op->storeBalance();
}

void IdleState::login() {
        context->setAttempts(0);
        context->changeState(CHECKPIN);
}

void IdleState::loginFail() {
        op->incorrectIdMsg();
}

void CheckPinState::correctPin() {
        context->changeState(TEMP);
        op->displayMenu();
}

void CheckPinState::incorrectPin(int max_attempts) {
        int attempts = context->getAttmpts();
        if (attempts >= max_attempts) {
                context->changeState(IDLE);
                op->tooManyAttemptMsg();
        } else if (attempts < max_attempts) {
                context->setAttempts(++attempts);
                op->incorrectPinMsg();
        }
}

void CheckPinState::logout() {
        context->changeState(IDLE);
}

void TempState::aboveMin() {
        context->changeState(READY);
}

void TempState::belowMin() {
        context->changeState(OVERDRAWN);
}

void ReadyState::balance() {
        op->displayBalance();
}

void ReadyState::lockFail() {
        op->incorrectPinMsg();
}

void ReadyState::lock() {
        context->changeState(LOCK);
}

void ReadyState::withdrawnFail() {
        op->noFundMsg();
}

void ReadyState::withdrawn() {
        context->changeState(TEMP);
        op->doWithdraw();
}

void ReadyState::deposit() {
        op->doDeposit();
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
        context->changeState(LOCK);
}

void OverdrawnState::deposit() {
        context->changeState(TEMP);
        op->doDeposit();
}

void OverdrawnState::withdrawn() {
        op->belowMinMsg();
}

void LockedState::balance() {
        op->displayBalance();
}

void LockedState::unlock() {
        context->changeState(TEMP);
}

void LockedState::close() {
        context->changeState(CLOSED);
}

void LockedState::unlockFail() {
        op->incorrectPinMsg();
}


ModelDrivenArch::ModelDrivenArch() {
        StartState *ss = new StartState();
        IdleState *is = new IdleState();
        CheckPinState *cps = new CheckPinState();
        ReadyState *rs = new ReadyState();
        OverdrawnState *os = new OverdrawnState();
        LockedState *ls = new LockedState();
        ClosedState *cs = new ClosedState();
        TempState *ts = new TempState();

        states.append(ss);
        states.append(is);
        states.append(cps);
        states.append(rs);
        states.append(os);
        states.append(ls);
        states.append(cs);
        states.append(ts);
 
        current = states[0];
}

ModelDrivenArch::~ModelDrivenArch() {
        for (int i = 0; i < states.size(); ++i) {
                delete stats[i];
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
                case LOCK:
                        current = states[5];
                        break;
                case CLOSED:
                        current = states[6];
                        break;
                case TEMP:
                        current = states[7];
                        break;
                default:
                        break;
        }
}

