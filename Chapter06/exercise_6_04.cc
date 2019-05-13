#include <iostream>

int fact() {
    int ret = 1;
    int val = 0;
    std::cout << "Input an intager:" << std::endl;
    std::cin >> val;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}

int main() {
    std::cout << fact() << std::endl;
}
