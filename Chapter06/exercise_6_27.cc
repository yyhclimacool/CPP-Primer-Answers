#include <iostream>
#include <initializer_list>

int sumup(std::initializer_list<int> il) {
    int sum = 0;
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        sum += *beg;
    return sum;
}

int main() {
    std::cout << sumup({1,2,3,4,5,6,7,8,9}) << std::endl;
}
