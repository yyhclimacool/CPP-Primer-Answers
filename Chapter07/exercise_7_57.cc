/*
 * Account类的声明和定义见Account.h/Account.cc
 */

#include "Account.h"
#include <iostream>

int main() {
    Account ac1("kevin", 100);
    std::cout << "interest rate is : " << ac1.rate() << std::endl;
    std::cout << ac1.getname() << " : now amount is : " << ac1.calculate() << std::endl;
    ac1.rate(0.4);
    std::cout << "interest rate is : " << ac1.rate() << std::endl;
    Account ac2("david", 1000);
    std::cout << ac2.getname() << " : now amount is : " << ac2.calculate() << std::endl;
}
