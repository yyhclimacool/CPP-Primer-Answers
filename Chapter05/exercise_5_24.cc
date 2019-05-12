#include <iostream>
#include <stdexcept>

int main() {
    int ival = 0, jval = 0;
    std::cin >> ival >> jval;
    if (jval == 0)
        throw std::runtime_error("can't divide 0!");
    std::cout << ival / jval << std::endl;
}
