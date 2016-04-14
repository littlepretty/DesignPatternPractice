#include "AbstractFactory.hpp"

DataStore *ConcreteFactory1::createDS() {
        return new DataStore1();
}

DataStore *ConcreteFactory2::createDS() {
        return new DataStore2();
}

StoreCardDataAction *ConcreteFactory1::createSCDA() {
        return new SCDAction1();
}

StoreCardDataAction *ConcreteFactory2::createSCDA() {
        return new SCDAction2();
}

IncorrectPinMsgAction *ConcreteFactory1::createIPMA() {
        return new IPMAction1();
}

IncorrectPinMsgAction *ConcreteFactory2::createIPMA() {
        return new IPMAction2();
}

IncorrectIdMsgAction *ConcreteFactory1::createIIMA() {
        return new IIMAction1();
}

IncorrectIdMsgAction *ConcreteFactory2::createIIMA() {
        return new IIMAction2();
}

TooManyAttemptMsgAction *ConcreteFactory1::createTMAMA() {
        return new TMAMAction1();
}

TooManyAttemptMsgAction *ConcreteFactory2::createTMAMA() {
        return new TMAMAction2();
}

PromptPinAction *ConcreteFactory1::createPPA() {
        return new PPAction1();
}

PromptPinAction *ConcreteFactory2::createPPA() {
        return new PPAction2();
}

DisplyMenuAction *ConcreteFactory1::createDMA() {
        return new DMAction1();
}

DisplyMenuAction *ConcreteFactory2::createDMA() {
        return new DMAction2();
}

DoDepositAction *ConcreteFactory1::createDDA() {
        return new DDAction1();
}

DoDepositAction *ConcreteFactory2::createDDA() {
        return new DDAction2();
}

NoFundMsgAction *ConcreteFactory1::createNFMA() {
        return new NFMAction1();
}

NoFundMsgAction *ConcreteFactory2::createNFMA() {
        return new NFMAction2();
}

DisplayBalanceAction *ConcreteFactory1::createDBA() {
        return new DBAction1();
}

DisplayBalanceAction *ConcreteFactory2::createDBA() {
        return new DBAction2();
}

DoWithdrawAction *ConcreteFactory1::createDWA() {
        return new DWAction1();
}

DoWithdrawAction *ConcreteFactory2::createDWA() {
        return new DWAction2();
}

BelowMinMsgAction *ConcreteFactory1::createBMMA() {
        return new BMMAction1();
}

BelowMinMsgAction *ConcreteFactory2::createBMMA() {
        return new BMMAction2();
}

DeductPenaltyAction *ConcreteFactory1::createDPA() {
        return new DPAction1();
}

DeductPenaltyAction *ConcreteFactory2::createDPA() {
        return new DPAction2();
}


