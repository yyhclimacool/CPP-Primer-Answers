#include <iostream>

int main() {
    int i = 42;
    int j = 44;
    int *ip = &i;
    ip = &j;
    *ip = 100;

    std::cout << ip << ":" << *ip << std::endl;

    return 0;
}
