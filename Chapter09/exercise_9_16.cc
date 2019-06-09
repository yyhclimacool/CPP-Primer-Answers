#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
    vector<int> ivec1 = {1,2,3,4,5,6};
    list<int> ilst(ivec1.begin(), ivec1.end());
    ilst.push_back(5);

    auto it1 = ivec1.cbegin();
    auto it2 = ilst.cbegin();
    for (; it1 != ivec1.cend() && it2 != ilst.cend(); ++it1, ++it2) {
        if (*it1 < *it2)
//            return -1;
            std::cout << -1 << std::endl;
        else if (*it1 > *it2)
//            return 1;
            std::cout << 1 << std::endl;
    }

    if (it1 == ivec1.cend() && it2 == ilst.cend())
//        return 0;
        std::cout << 0 << std::endl;
    else if (it1 != ivec1.cend() && it2 == ilst.cend())
//        return 1;
        std::cout << 1 << std::endl;
    else if (it1 == ivec1.cend() && it2 != ilst.cend())
//        return -1;
        std::cout << -1 << std::endl;
}
