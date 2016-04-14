#ifndef _ACCOUNTS_HPP
#define _ACCOUNTS_HPP

#include "ModelDrivenArch.hpp"
#include "DataStore.hpp"

class AbstractFactory;

class Account1 {
        private:
                ModelDrivenArch *mda;
                DataStore1 *ds; 
                const int min_balance;
                const int max_attempts;
        public:
                Account1(ModelDrivenArch *m, int mb = 500, int ma = 3):
                        mda(m), min_balance(mb), max_attempts(ma) {};
                virtual ~Account1() {
                        delete ds;
                }

                void init(AbstractFactory *af);
        
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
        private:
                ModelDrivenArch *mda;
                DataStore2 *ds; 
                const int min_balance;
                const int max_attempts;
        public:
                Account2(ModelDrivenArch *m, int mb = 0, int ma = 2):
                        mda(m), min_balance(mb), max_attempts(ma) {}; 
                virtual ~Account2() {
                        delete ds;
                }

                void init(AbstractFactory *af);

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

#endif

