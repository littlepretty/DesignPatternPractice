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
        ds->setTempB(b);
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









