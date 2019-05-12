#include <iostream>
#include <string>

int get_size() {
    std::string str;
    std::cin >> str;
    return static_cast<int>(str.size()) - 3;
}

int main() {
    while (int sz = get_size() && sz <= 0){ 
        std::cout << "Empty" << std::endl;
    }
}
