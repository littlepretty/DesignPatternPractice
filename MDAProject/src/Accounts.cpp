#include "Accounts.hpp"
#include "AbstractFactory.hpp"
#include "ModelDrivenArch.hpp"


void Account1::init(AbstractFactory *af) {
        ds = af->createDataStore();
}

const int Account1::min_balance = 500;
const int Account1::max_attempts = 3;

void Account1::open(string p, string y, float a) {
        ds->setTempPin(p);
        ds->setTempId(y);
        ds->setTempBalance(b);
        mda->open();
}

void Account1::pin(string x) {
        if (x == ds->pin) {
                mda->correctPin();
                if (ds->balance > min_balance) {
                        mda->aboveMin();
                } else {
                        mda->belowMin();
                }
        } else {
                mda->incorrectPin(max_attempts);
        }
}

void Account1::deposit(float d) {
        ds->setTempD(d);
        mda->deposite();
        if (ds->getBalance() > min_balance) {
                mda->aboveMin();
        } else {
                mda->belowMin();
        }
}


void Account1::withdraw(float w) {
        ds->setTempW(w);
        if (ds->getBalance() <= min_balance) {
                mda->withdrawFail();
        } else {
                mda->withdraw();
        }
        if (ds->getBalance() > min_balance) {
                mda->aboveMin();
        } else {
                mda->belowMin();
        }
}

void Account1::balance() {
        mda->balance();
}

void Account1::login(string y) {
        if (y == ds->getId()) {
                mda->login();
        } else {
                mda->loginFail();
        }
}

void Account1::logout() {
        mda->logout();
}

void Account1::lock(string x) {
        if (x == ds->getPin()) {
                mda->lock();
        } else {
                mad->lockFail();
        }
}

void Account1::unlock(string x) {
        if (x == ds->getPin()) {
                mda->unlock();
                if (ds->getBalance() > min_balance) {
                        mda->aboveMin();
                } else {
                        mda->belowMin();
                }
        } else {
                mda->unlockFail();
        }
}

const int Account2::min_balance = 0;
const int Account2::max_attempts = 2

void Account2::init(AbstractFactory *af) {
        ds = af->createDS();
}

void Account2::OPEN(int p, int y, int a) {
        ds->setTempPin(p);
        ds->setTempId(y);
        ds->setTempBalance(a);
        mda->open();
}

void Account2::PIN(int x) {
        if (x == ds->getPin()) {
                mda->correctPin();
                mda->aboveMin();
        } else {
                mda->incorrectPin(max_attempts);
        }
}

void Account2::DEPOSIT(int d) {
        ds->setTempD(d);
        mda->deposit();
        mda->aboveMin();
}

void Account2::WITHDRAW(int w) {
        ds->setTempW(w);
        if (ds->getBalance() > min_balance) {
                mda->withdraw();
                mda->aboveMin();
        } else {
                mda->withdrawFail();
        }
}

void Account2::BALANCE() {
        mda->balance();
}

void Account2::LOGIN(int y) {
        if (y == ds->getId()) {
                mda->login();
        } else {
                mda->loginFail();
        }
}

void Account2::LIGOUT() {
        mda->logout();
}

void Account2::suspend() {
        mda->lock();
}

void Account2::activate() {
        mda->unlock();
        mda->aboveMin();
}

void Account2::close() {
        mda->close();
}

