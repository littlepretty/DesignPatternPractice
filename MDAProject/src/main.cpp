#include <iostream>
#include "MDABankAccountConfig.h"
#include "ModelDrivenArch.hpp"
#include "AbstractFactory.hpp"
#include "Accounts.hpp"


using namespace std;

void testAccount1() {
        ModelDrivenArch* mda = new ModelDrivenArch();
        ConcreateFactory1* cf1 = new ConcreateFactory1();
        Account1* a1 = new Account1(mda);
        OutputProcessor* op1 = new OutputProcessor();

        a1.init(cf1);
        op1.init(cf1);

        delete op1;
        delete a1;
}

void testAccount2() {
        ModelDrivenArch* mda = new ModelDrivenArch();
        ConcreateFactory2* cf2 = new ConcreateFactory2();
        Account2* a2 = new Account2(mda);
        OutputProcessor* op2 = new OutputProcessor();

        a2.init(cf2);
        op2.init(cf2);

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
