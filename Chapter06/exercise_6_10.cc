#include <iostream>

void myswap(int *p1, int *p2) {
    int tmp = *p2;
    *p2 = *p1;
    *p1 = tmp;
}

int main() {
    int a = 10, b = 42;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    myswap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
}
