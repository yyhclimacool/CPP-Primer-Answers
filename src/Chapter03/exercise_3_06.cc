#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str{"Hello, World!"};
    for (auto &c : str)
        c = 'X';
    std::cout << str << std::endl;
    return 0;
}
