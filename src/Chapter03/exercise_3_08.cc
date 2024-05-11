#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str{"Hello, World!"};
    // Using while
    decltype(str.size()) index = 0;
    while (index < str.size())
        str[index++] = 'X';
    std::cout << str << std::endl;

    // Using trivial for loop
    str = "Hello, World!";
    for (decltype(str.size()) idx = 0; idx < str.size(); ++idx)
        str[idx] = 'X';
    std::cout << str << std::endl;

    return 0;
}
