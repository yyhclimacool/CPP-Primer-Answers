#include <iostream>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a; // c is a int
    decltype(a = b) d = a; // d is a int &

    ++d;
    // a = 4, d = 4
    std::cout << "a = " << a << ", d = " << d << std::endl;

    return 0;
}
