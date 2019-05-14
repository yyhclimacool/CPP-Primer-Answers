#include <iostream>
#include <string>
#include <cctype>

bool have_upper_case(const std::string &s) {
    for (const auto c : s) 
        if (isupper(c))
            return true;
    return false;
}

void mytransform(std::string &s) {
    for (auto &c : s) 
        c = tolower(c);
}

int main() {
    std::cout << have_upper_case("fine By me!") << std::endl;
    std::string s("FINE BY ME!");
    mytransform(s);
    std::cout << s << std::endl;
}
