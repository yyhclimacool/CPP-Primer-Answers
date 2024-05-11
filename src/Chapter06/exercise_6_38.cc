#include <iostream>

int odd[] = {1,3,5,7,9};
int even[] = {2,4,6,8,0};

decltype(odd) &arrPtr(int i) {
    return (i % 2) ? odd : even;
}

int main() {
    auto &ia = arrPtr(1);
    for (auto e : ia)
        std::cout << e << ' ';
    std::cout << std::endl;
}
