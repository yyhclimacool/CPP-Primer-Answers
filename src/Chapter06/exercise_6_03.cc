#include <iostream>

int fact(int x) {
    int ret = 1;
    while (x > 1) {
        ret *= x--;
    }
    return ret;
}

int main() {
    std::cout << fact(5) << std::endl;
    std::cout << fact(6) << std::endl;
    std::cout << fact(7) << std::endl;
}
