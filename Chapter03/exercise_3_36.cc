#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int a[] = {1,2,3,4,5,6};
    int b[] = {1,2,3,4,5,6,7,8,9};

    if ((end(a) - begin(a)) == (end(b) - begin(b))) {
        int len = end(a) - begin(a);
        for (int idx = 0; idx != len; ++idx) {
            if (a[idx] != b[idx])
                std::cout << "Not equal!" << std::endl;
        }
        std::cout << "Equal!" << std::endl;
    } else 
        std::cout << "Not equal!" << std::endl;

    std::vector<int> v1(begin(a), end(a)), v2(begin(b), end(b));
    if (v1 == v2)
        std::cout << "Equal!" << std::endl;
    else 
        std::cout << "Not equal!" << std::endl;
}
