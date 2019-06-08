#include "Account.h"

void Account::rate(double rt) {
    interestRate_ = rt;
}

// double Account::interestRate = initRate();
double Account::interestRate_ = 0.33;

double Account::initRate() {
    return 0.35;
}
