#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string str("Test string");
    std::string::iterator iter = str.begin();
    while (iter != str.end()) {
        std::cout << *iter++;
    }
    std::cout << std::endl;
}
