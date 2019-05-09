#include <iostream>

int main() {
    char ch;
    size_t owlcnt = 0;
    while (std::cin >> ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            ++owlcnt;
    }
    std::cout << owlcnt << std::endl;
}
