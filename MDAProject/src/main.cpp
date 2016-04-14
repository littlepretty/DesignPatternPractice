#include <iostream>
#include "MDABankAccountConfig.h"
#include "ModelDrivenArch.hpp"
#include "AbstractFactory.hpp"
#include "Accounts.hpp"


using namespace std;

void testAccount1() {
        ConcreteFactory1* cf1 = new ConcreteFactory1();
        OutputProcessor* op1 = new OutputProcessor();
        op1->init(cf1);
        
        ModelDrivenArch* mda = new ModelDrivenArch(op1);
        Account1* a1 = new Account1(mda);
        a1->init(cf1);

        delete op1;
        delete a1;
}

void testAccount2() {
        ConcreteFactory2* cf2 = new ConcreteFactory2();
        OutputProcessor* op2 = new OutputProcessor();
        op1->init(cf2);
        
        ModelDrivenArch* mda = new ModelDrivenArch(op2);
        Account1* a2 = new Account2(mda);
        a1->init(cf2);

        delete op2;
        delete a2;
}

int main(int argc, char *argv[]) {
        cout<<"Hello CMake!"<<endl;
        cout<<argv[0]<<" Version "<<MDABankAccount_VERSION_MAJOR
                <<"."<<MDABankAccount_VERSION_MINOR<<endl;
        testAccount1();
        testAccount2();
        return 0;
}
