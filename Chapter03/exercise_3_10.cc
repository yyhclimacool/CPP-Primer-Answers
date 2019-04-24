#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::cout << "Input a string :" << std::endl;
    std::string str;
    std::cin >> str;

    for (const auto &c : str)
        if (!std::ispunct(c)) // with or without std:: both are OK
            std::cout << c;
    std::cout << std::endl;
    return 0;
}
