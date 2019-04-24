#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str{"Hello, World!"};
    for (char c : str) // Must be a reference to make a change
        c = 'X';
    std::cout << str << std::endl;
    return 0;
}
