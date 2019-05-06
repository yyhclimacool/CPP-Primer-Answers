#include <iostream>
#include <vector>
#include <iterator>

int main() {
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> iv(std::begin(ia), std::end(ia));
    for (auto &i : iv)
        std::cout << i << " ";
    std::cout << std::endl;
}
