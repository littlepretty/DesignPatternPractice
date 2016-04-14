#ifndef _ACTIONS_HPP
#define _ACTIONS_HPP

#include "DataStore.hpp"

class AbstractFactory;

class StoreCardDataAction {
        public:
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

class DeductPenaltyAction {
        protected:
                const float penalty;
        public:
                DeductPenaltyAction(float p = 0.0f): penalty(p) {};
                virtual void payPenalty(DataStore *ds) = 0;
};

class DPAction1: public DeductPenaltyAction {
        public:
                DPAction1(float p = 20.0f): DeductPenaltyAction(p) {};
                virtual void payPenalty(DataStore *ds);
};

class DPAction2: public DeductPenaltyAction {
        public:
                virtual void payPenalty(DataStore *ds);
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
                DeductPenaltyAction *dpa;
        public:
                OutputProcessor() {};
                virtual ~OutputProcessor();
                
                void init(AbstractFactory *af);
                void storeCardData();
                void incorrectPinMsg();
                void incorrectIdMsg();
                void tooManyAttemptMsg();
                void promptPin();
                void displayMenu();
                void doDeposit();
                void noFundMsg();
                void displayBalance();
                void doWithdraw();
                void belowMinMsg();
                void payPenalty();
};

#endif

