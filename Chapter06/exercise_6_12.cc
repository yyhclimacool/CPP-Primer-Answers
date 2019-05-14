#include <iostream>

void myswap(int &lhs, int &rhs) {
    int tmp = rhs;
    rhs = lhs;
    lhs = tmp;
}

int main() {
    int val1 = 10, val2 = 42;
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;
    myswap(val1, val2);
    std::cout << "val1 = " << val1 << ", val2 = " << val2 << std::endl;
}
