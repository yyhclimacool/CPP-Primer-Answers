#include <iostream>
#include <string>

int main() {
    std::string ans;
    do {
        std::string v1, v2;
        std::cout << "Input two strings:" << std::endl;
        std::cin >> v1 >> v2;
        std::cout << (v1.size() < v2.size() ? v1 : v2) << std::endl;
        std::cout << "Continue ? yes or no :" << std::endl;
        std::cin >> ans;
    } while (ans.size()i && ans[0] != 'n');
}
