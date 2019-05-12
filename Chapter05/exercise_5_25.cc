#include <iostream>
#include <stdexcept>

int main() {
    int ival = 0, jval = 0;
    while (std::cin >> ival >> jval) {
        try {
            if (jval == 0)
                throw std::runtime_error("can't divide 0!");
            std::cout << ival / jval << std::endl;
        } catch (std::runtime_error &e) {
            std::cout << e.what() << std::endl << "Continue ? input y or n" << std::endl;
            char ch = '\0';
            std::cin >> ch;
            if (!ch || ch == 'n')
                break;
        }
    }
}
