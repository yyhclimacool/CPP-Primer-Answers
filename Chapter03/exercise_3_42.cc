#include <iostream>
#include <vector>

int main() {
    std::vector<int> iv = {0,1,2,3,4,5,6,7,8,9};

    int ia[iv.size()] = {0};
    
    for (decltype(iv.size()) ix = 0; ix < iv.size(); ++ix) 
        ia[ix] = iv[ix];
    for(const auto &i : iv)
        std::cout << i << " ";
    std::cout << std::endl;
}
