#include <iostream>
#include "AbstractFactory.hpp"
#include "ModelDrivenArch.hpp"
#include "DataStore.h"

class Account {
        private:
                ModelDrivenArch *mda;
                DataStore *ds; 
                const int min_balance;
                const int max_attempts;
        public:
                Account() {}
                Account(ModelDrivenArch *_mda): mda(_mda) {}
                virtual ~Account() {
                        delete mda;
                        delete ds;
                }
                virtual void init(AbstractFactory *af) = 0;
}

class Account1 {
        public:
                Account1() {}
                virtual ~Account1() {};

                virtual void init(AbstractFactory *af);
        
                void open(string p, string y, float a);
                void pin(string x);
                void deposit(float d);
                void withdraw(float w);
                void balance();
                void login(string y);
                void logout();
                void lock(string x);
                void unlock(string x);
};

class Account2 {
        public:
                Account2() {}
                virtual ~Account2() {}

                virtual void init(AbstractFactory *af);

                void OPEN(int p, int y, int a);
                void PIN(int x);
                void DEPOSIT(int d);
                void WITHDRAW(int w);
                void BALANCE();
                void LOGIN(int y);
                void LOGOUT();
                void suspend();
                void activate();
                void close();
};

