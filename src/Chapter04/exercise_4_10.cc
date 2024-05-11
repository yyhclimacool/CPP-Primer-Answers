#include <iostream>

int main() {
    int ival;
    while (std::cin >> ival && ival != 42)
        ;
    std::cout << "42 encountered" << std::endl;
}
