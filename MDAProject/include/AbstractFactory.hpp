#include <iostream>
#include "DataStore.h"
#include "Actions.h"

class AbstractFactory {
        public:
                AbstractFacotry() {}
                virtual AbstractFacotry() {}

                virtual DataStore *createDS() = 0;
                virtual StorePinAction *createSPA() = 0;
                virtual StoreBalanceAction *createSBA() = 0;
                virtual StoreIdAction *createSIA() = 0;
                virtual IncorrectPinMsgAction *createIPMA() = 0;
                virtual IncorrectIdMsgAction *createIIMA() = 0;
                virtual TooManyAttemptMsgAction *createTMAMA() = 0;
                virtual PromptPinAction *createPPA() = 0;
                virtual DisplyMenuAction *createDMA() = 0;
                virtual DoDepositAction *createDDA() = 0;
                virtual NoFundMsgAction *createNFMA() = 0;
                virtual DisplayBalanceAction *createDBA() = 0;
                virtual DoWithdrawAction *createDWA() = 0;
                virtual BelowMinMsgAction *createBMMA() = 0;
};

class ConcreteFactory1: public AbstractFacotry {
        public:
                ConcreteFactory1() {}
                virtual ~ConcreteFactory1() {}

                virtual DataStore *createDS();
                virtual StorePinAction *createSPA();
                virtual StoreBalanceAction *createSBA();
                virtual StoreIdAction *createSIA();
                virtual IncorrectPinMsgAction *createIPMA();
                virtual IncorrectIdMsgAction *createIIMA();
                virtual TooManyAttemptMsgAction *createTMAMA();
                virtual PromptPinAction *createPPA();
                virtual DisplyMenuAction *createDMA();
                virtual DoDepositAction *createDDA();
                virtual NoFundMsgAction *createNFMA();
                virtual DisplayBalanceAction *createDBA();
                virtual DoWithdrawAction *createDWA();
                virtual BelowMinMsgAction *createBMMA();
};

class ConcreteFactory2: public AbstractFacotry {
        public:
                ConcreteFactory2() {}
                virtual ~ConcreteFactory2() {}
                
                virtual DataStore *createDS();
                virtual StorePinAction *createSPA();
                virtual StoreBalanceAction *createSBA();
                virtual StoreIdAction *createSIA();
                virtual IncorrectPinMsgAction *createIPMA();
                virtual IncorrectIdMsgAction *createIIMA();
                virtual TooManyAttemptMsgAction *createTMAMA();
                virtual PromptPinAction *createPPA();
                virtual DisplyMenuAction *createDMA();
                virtual DoDepositAction *createDDA();
                virtual NoFundMsgAction *createNFMA();
                virtual DisplayBalanceAction *createDBA();
                virtual DoWithdrawAction *createDWA();
                virtual BelowMinMsgAction *createBMMA();
};

