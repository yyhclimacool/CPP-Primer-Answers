/*
 * Using escape sequence
 */

#include <iostream>

int main() {
    std::cout << "2\x4d\n";

    std::cout << "2\t\x4d\n";

    return 0;
}
