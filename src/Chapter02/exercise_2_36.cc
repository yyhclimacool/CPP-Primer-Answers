#include <iostream>

int main() {
    int a = 3, b = 4;
    decltype(a) c = a; // c is a int
    decltype((b)) d = a; // d is a int &

    ++c;
    ++d;

    /*
     * a = 4
     * b = 4
     * c = 4
     * d = 4
     */
    std::cout << "a = " << a 
              << ", b = " << b 
              << ", c = " << c 
              << ", d = " << d 
              << std::endl;
    return 0;
}
