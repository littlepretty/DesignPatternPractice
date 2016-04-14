#ifndef _ACTIONS_HPP
#define _ACTIONS_HPP

#include "DataStore.hpp"

class AbstractFactory;

class StoreCardDataAction {
        public:
                StoreCardDataAction() {};
                virtual ~StorePinAction() {};

                virtual void storeCardData(DataStore *ds) = 0;
};

class SCDAction1: public StoreCardDataAction {
        public:
                virtual void storeCardData(DataStore *ds);
};

class SCDAction2: public StoreCardDataAction {
        public:
                virtual void storeCardData(DataStore *ds);
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
                virtual void belowMinMsg() = 0;
};

class BMMAction1: public BelowMinMsgAction {
        public:
                virtual void belowMinMsg();
};

class BMMAction2: public BelowMinMsgAction {
        public:
                virtual void belowMinMsg();
};

class PenaltyAction {
        public:
                virtual void penalty() = 0;
};

class PAction1: public PenaltyAction {
        public:
                virtual void penalty();
};

class PAction2: public PenaltyAction {
        public:
                virtual void penalty();
};


class OutputProcessor {
        private:
                DataStore *ds;
                StoreCardDataAction *scda;
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
                PenaltyAction *pa;
        public:
                OutputProcessor();
                virtual ~OutputProcessor() {
                       delete ds;
                       delete scda;
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
                       delete pa;
                };
                
                void init(AbstractFactory *af);

                void storeCardData() {
                        scda->storeCardData(ds);
                };
                void incorrectPinMsg() {
                        ipma->incorrectPinMsg();
                };
                void incorrectIdMsg() {
                        iima->incorrectIdMsg();
                };
                void tooManyAttemptMsg() {
                        tmama->tooManyAttemptMsg();
                };
                void promptPin() {
                        ppa->promptPin();
                };
                void displayMenu() {
                        dma->displayMenu();
                };
                void doDeposit() {
                        dda->doDeposit(ds);
                };
                void noFundMsg() {
                        nfma->noFundMsg();
                };
                void displayBalance() {
                        dba->displayBalance(ds);
                };
                void doWithdraw() {
                        dwa->doWithdraw(ds);
                };
                void belowMinMsg() {
                        bmma->belowMinMsg();
                };
                void penalty() {
                        pa->penalty();
                };
};

#endif

