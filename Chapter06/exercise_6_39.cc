#include <iostream>

int *reset(int *pi) {
    *pi = 0;
    return pi;
}

double *reset(double *pd) {
    *pd = 0.0;
    return pd;
}

int main() {
    int ival = 42;
    double dval = 42.42;
    std::cout << ival << " " << dval << std::endl;

    reset(&ival);
    reset(&dval);
    std::cout << ival << " " << dval << std::endl;
}
