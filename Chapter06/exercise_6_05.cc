#include <iostream>

int myabs(int val) {
    return val >= 0 ? val : -val;
}

int main() {
    std::cout << myabs(-5) << std::endl;
    std::cout << myabs(4) << std::endl;
    std::cout << myabs(0) << std::endl;
}
