#include <iostream>

void reset(int &val) {
    val = 0;
}

int main() {
    int ival = 42;
    std::cout << "ival = " << ival << std::endl;
    reset(ival);
    std::cout << "ival = " << ival << std::endl;
}
