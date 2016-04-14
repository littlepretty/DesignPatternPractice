#include <iostream>
#include "Actions.hpp"
#include "DataStore.hpp"
#include "AbstractFactory.hpp"

using namespace std;


void SCDAction1::storeCardData(DataStore* ds) {
        DataStore1 *ds1 = (DataStore1 *)ds;
        ds1->setPin(ds1->getTempPin());
        ds1->setId(ds1->getTempId());
        ds1->setBalance(ds1->getTempBalance());
}

void SCDAction2::storeCardData(DataStore* ds) {
        DataStore2 *ds2 = (DataStore2 *)ds;
        ds2->setPin(ds2->getTempPin());
        ds2->setId(ds2->getTempId());
        ds2->setBalance(ds2->getTempBalance());
}


void IPMAction1::incorrectPinMsg() {
        cout<<"\tIncorrect Pin Input at Account 1\n";
}

void IPMAction2::incorrectPinMsg() {
        cout<<"\tIncorrect Pin Input at Account 2\n";
}


void IIMAction1::incorrectIdMsg() {
        cout<<"\tIncorrect ID Input at Account 1\n";
}

void IIMAction2::incorrectIdMsg() {
        cout<<"\tIncorrect ID Input at Account 2\n";
}


void TMAMAction1::tooManyAttemptMsg() {
        cout<<"\t#Attempts Exceed Maximum Allowed at Account1\n";
}

void TMAMAction2::tooManyAttemptMsg() {
        cout<<"\t#Attempts Exceed Maximum Allowed at Account2\n";
}


void PPAction1::promptPin() {
        cout<<"\tPlease Input PIN to Proceed at Account1\n";
}

void PPAction2::promptPin() {
        cout<<"\tPlease Input PIN to Proceed at Account2\n";
}


void DMAction1::displayMenu() {
        cout<<"\tMenu at Accout1\n";
        cout<<"\t\t1. Display Balance\n";
        cout<<"\t\t2. Make Deposit\n";
        cout<<"\t\t3. Withdraw\n";
        cout<<"\t\t4. Lock Account\n";
        cout<<"\t\t5. Unlock Account\n";
        cout<<"\t\t6. Logout\n";
}

void DMAction2::displayMenu() {
        cout<<"\tMenu at Accout2\n";
        cout<<"\t\t1. Display Balance\n";
        cout<<"\t\t2. Make Deposit\n";
        cout<<"\t\t3. Withdraw\n";
        cout<<"\t\t4. Suspend Account\n";
        cout<<"\t\t5. Activate Account\n";
        cout<<"\t\t6. Logout\n";
        cout<<"\t\t7. Close\n";
}

void DDAction1::doDeposit(DataStore *ds) {
        DataStore1 *ds1 = (DataStore1 *)ds;
        ds1->setBalance(ds1->getBalance() + ds1->getTempD());
}

void DDAction2::doDeposit(DataStore *ds) {
        DataStore2 *ds2 = (DataStore2 *)ds;
        ds2->setBalance(ds2->getBalance() + ds2->getTempD());
}


void NFMAction1::noFundMsg() {
        cout<<"\tZero Balance at Account1\n";
}

void NFMAction2::noFundMsg() {
        cout<<"\tZero Balance at Account2\n";
}


void DBAction1::displayBalance(DataStore *ds) {
        DataStore1 *ds1 = (DataStore1 *)ds;
        cout<<"\tCurrent Balance = $"<<ds1->getBalance()<<" at Account1\n";
}

void DBAction2::displayBalance(DataStore *ds) {
        DataStore2 *ds2 = (DataStore2 *)ds;
        cout<<"\tCurrent Balance = $"<<ds2->getBalance()<<" at Account2\n";
}

void DWAction1::doWithdraw(DataStore *ds) {
        DataStore1 *ds1 = (DataStore1 *)ds;
        ds1->setBalance(ds1->getBalance() - ds1->getTempW());
}

void DWAction2::doWithdraw(DataStore *ds) {
        DataStore2 *ds2 = (DataStore2 *)ds;
        ds2->setBalance(ds2->getBalance() - ds2->getTempW());
}


void BMMAction1::belowMinMsg() {
        cout<<"\tBalance Below Minimum Allowed at Account1\n";
}

void BMMAction2::belowMinMsg() {
        cout<<"\tBalance Below Minimum Allowed at Account2\n";
}


void DPAction1::payPenalty(DataStore *ds) {
        DataStore1 *ds1 = (DataStore1 *)ds;
        ds1->setBalance(ds1->getBalance() - penalty);
}

void DPAction2::payPenalty(DataStore *ds) {
        DataStore2 *ds2 = (DataStore2 *)ds;
        ds2->setBalance(ds2->getBalance() - penalty);
}


void OutputProcessor::init(AbstractFactory *af) {
        scda = af->createSCDA();
        ipma = af->createIPMA();
        iima = af->createIIMA();
        tmama = af->createTMAMA();
        ppa = af->createPPA();
        dma = af->createDMA();
        nfma = af->createNFMA();
        dba = af->createDBA();
        dwa = af->createDWA();
        bmma = af->createBMMA();
        dpa = af->createDPA();
}

OutputProcessor::~OutputProcessor() {
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
        delete dpa;
};

void OutputProcessor::storeCardData() {
        scda->storeCardData(ds);
}

void OutputProcessor::incorrectPinMsg() {
        ipma->incorrectPinMsg();
}

void OutputProcessor::incorrectIdMsg() {
        iima->incorrectIdMsg();
}

void OutputProcessor::tooManyAttemptMsg() {
        tmama->tooManyAttemptMsg();
}

void OutputProcessor::promptPin() {
        ppa->promptPin();
}

void OutputProcessor::displayMenu() {
        dma->displayMenu();
}

void OutputProcessor::doDeposit() {
        dda->doDeposit(ds);
}

void OutputProcessor::noFundMsg() {
        nfma->noFundMsg();
}

void OutputProcessor::displayBalance() {
        dba->displayBalance(ds);
}

void OutputProcessor::doWithdraw() {
        dwa->doWithdraw(ds);
}

void OutputProcessor::belowMinMsg() {
        bmma->belowMinMsg();
}

void OutputProcessor::payPenalty() {
        dpa->payPenalty(ds);
}



