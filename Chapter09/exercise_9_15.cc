#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> ivec1 = {1,2,3,4,5,6};
    vector<int> ivec2(ivec1);
    if (ivec1 == ivec2)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;
}
