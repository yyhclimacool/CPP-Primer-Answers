#include <iostream>
#include <vector>

void recursive_print(const std::vector<int> &vec, std::vector<int>::size_type i) {
#ifndef NDEBUG
    std::cout << "index is: " << i << std::endl;
#endif
    if (i == vec.size()) {
        std::cout << std::endl;
        return;
    }
    std::cout << vec[i] << ' ';
    recursive_print(vec, ++i);
}

int main() {
    std::vector<int> ivec = {1,2,3,43,54,5,6,7,8};
    recursive_print(ivec, 0);
}
