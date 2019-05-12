#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> v1 = {1,2,3,4,5,4,4,4,4,4,5};
    std::vector<int> v2 = {1,2,3,5,5,5,5,5,5,5};
    std::vector<int> v3 = {1,2,3,4};

    auto len1 = v1.size();
    auto len2 = v2.size();
    auto len3 = v3.size();

    decltype(v1.size()) idx = 0;
    for (; idx != len3 && v3[idx] == v1[idx]; ++idx)
        ;
    if (idx == len3)
        std::cout << "v3 is part of v1" << std::endl;

    idx = 0;
    while (idx != len3 && v3[idx] == v2[idx]) {
        ++idx;
    }
    if (idx == len3)
        std::cout << "v3 is part of v2" << std::endl;
    else 
        std::cout << "v3 is not part of v2" << std::endl;
}
