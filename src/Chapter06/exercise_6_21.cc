#include <iostream>

int compare(int a, const int *b) {
    return a > *b ? a : *b; 
}

int main() {
    int val = 7;
    std::cout << compare(6, &val) << std::endl;
}
