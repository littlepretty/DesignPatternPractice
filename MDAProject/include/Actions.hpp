#include <iostream>

class StorePinAction {
        public:
                virtual void storePin(DataStore *ds) = 0;
};

class SPAction1: public StorePinAction {
        public:
                virtual void storePin(DataStore *ds);
};

class SPAction2: public StorePinAction {
        public:
                virtual void storePin(DataStore *ds);
};

class StoreBalanceAction {
        public:
                virtual void storeBalance(DataStore *ds) = 0;
};

class SBAction1: public StoreBalanceAction {
        public:
                virtual void storeBalance(DataStore *ds);
};

class SBAction2: public StoreBalanceAction {
        public:
                virtual void storeBalance(DataStore *ds);
}

class StoreIdAction {
        public:
                virtual void storeId(DataStore *ds) = 0;
};

class SIAction1: public StoreIdAction {
        public:
                virtual void storeId(DataStore *ds);
};

class SIAction2: public StoreIdAction {
        public:
                virtual void storeId(DataStore *ds);
};

class IncorrectPinMsgAction {
        public:
                virtual void incorrectPinMsg() = 0;
};

class IPMAction1: public IncorrectPinMsgAction {
        public:
                virtual void incorrectPinMsg();
};

class IPMAction2: public IncorrectPinMsgAction {
        public:
                virtual void incorrectPinMsg();
};

class IncorrectIdMsgAction {
        public:
                virtual void incorrectIdMsg() = 0;
};

class IIMAction1: public IncorrectIdMsgAction {
        public:
                virtual void incorrectIdMsg();
};

class IIMAction2: public IncorrectIdMsgAction {
        public:
                virtual void incorrectIdMsg();
};

class TooManyAttemptMsgAction {
        public:
                virtual void tooManyAttemptMsg() = 0;
};

class TMAMAction1: public TooManyAttemptMsgAction {
        public:
                virtual void tooManyAttemptMsg();
};

class TMAMAction2: public TooManyAttemptMsgAction {
        public:
                virtual void tooManyAttemptMsg();
};

class PromptPinAction {
        public:
                virtual void promptPin() = 0;
};

class PPAction1: public PromptPinAction { 
        public:
                virtual void promptPin();
};

class PPAction2: public PromptPinAction { 
        public:
                virtual void promptPin();
};

//class StoreAttemptAction {
        //public:
                //void storeAttempt() = 0;
//};

//class SAAction1: public StoreAttemptAction {
        //public:
                //void storeAttempt();
//};

//class SAAction2: public StoreAttemptAction {
        //public:
                //void storeAttempt();
//};

class DisplyMenuAction {
        public:
                virtual void displayMenu() = 0;
};

class DMAction1: public DisplyMenuAction {
        public:
                virtual void displayMenu();
};

class DMAction2: public DisplyMenuAction {
        public:
                virtual void displayMenu();
};

class DoDepositAction {
        public:
                virtual void doDeposit(DataStore *ds) = 0;
};

class DDAction1: public DoDepositAction {
        public:
                virtual void doDeposit(DataStore *ds);
};

class DDAction2: public DoDepositAction {
        public:
                virtual void doDeposit(DataStore *ds);
};

class NoFundMsgAction {
        public:
                virtual void noFundMsg() = 0;
};

class NFMAction1: public NoFundMsgAction {
        public:
                virtual void noFundMsg();
};

class NFMAction2: public NoFundMsgAction {
        public:
                virtual void noFundMsg();
};

class DisplayBalanceAction {
        public:
                virtual void displayBalance(DataStore *ds) = 0;
};

class DBAction1: public DisplayBalanceAction {
        public:
                virtual void displayBalance(DataStore *ds);
};

class DBAction2: public DisplayBalanceAction {
        public:
                virtual void displayBalance(DataStore *ds);
};

class DoWithdrawAction {
        public:
                virtual void doWithdraw(DataStore *ds) = 0;
};

class DWAction1: public DoWithdrawAction {
        public:
                virtual void doWithdraw(DataStore *ds);
};

class DWAction2: public DoWithdrawAction {
        public:
                virtual void doWithdraw(DataStore *ds);
};

class BelowMinMsgAction {
        public:
                virtual virtual void belowMinMsg() = 0;
};

class BMMAction1: public BelowMinMsgAction {
        public:
                virtual void belowMinMsg();
};

class BMMAction2: public BelowMinMsgAction {
        public:
                virtual void belowMinMsg();
};

class OutputProcessor {
        private:
                DataStore *ds;
                StorePinAction *spa;
                StoreBalanceAction *sba;
                StoreIdAction *sia;
                IncorrectPinMsgAction *ipma;
                IncorrectIdMsgAction *iima;
                TooManyAttemptMsgAction *tmama;
                PromptPinAction *ppa; 
                DisplyMenuAction *dma;
                DoDepositAction *dda;
                NoFundMsgAction *nfma;
                DisplayBalanceAction *dba;
                DoWithdrawAction *dwa;
                BelowMinMsgAction *bmma;
        public:
                OutputProcessor(DataStore *ds);
                virtual ~OutputProcessor() {
                       delete ds;
                       delete spa;
                       delete sba;
                       delete sia;
                       delete ipma;
                       delete iima;
                       delete tmama;
                       delete ppa;
                       delete dma;
                       delete dda;
                       delete nfma;
                       delete dba;
                       delete dwa;
                       delete bmma;
                };
                
                void init(AbstractFactory *af);

                void storePin() {
                        spa->storePin(ds);
                }
                void storeBalance() {
                        sba->storeBalance(ds);
                }
                void storeId() {
                        sia->storeId(ds);
                }
                void incorrectPinMsg() {
                        ipma->incorrectPinMsg();
                }
                void incorrectIdMsg() {
                        iima->incorrectIdMsg();
                }
                void tooManyAttemptMsg() {
                        tmama->tooManyAttemptMsg();
                }
                void promptPin() {
                        ppa->promptPin();
                }
                void displayMenu() {
                        dma->displayMenu();
                }
                void doDeposit() {
                        dda->doDeposit(ds);
                }
                void noFundMsg() {
                        nfma->noFundMsg();
                }
                void displayBalance() {
                        dba->displayBalance(ds);
                }
                void doWithdraw() {
                        dwa->doWithdraw(ds);
                }
                void belowMinMsg() {
                        bmma->belowMinMsg();
                }
};


