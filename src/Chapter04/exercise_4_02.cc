#include <iostream>
#include <vector>

int main() {
    std::vector<int> ivec(10, 42);

    std::cout << *(ivec.begin()) << std::endl;
    std::cout << (*(ivec.begin())) + 1 << std::endl;
}
