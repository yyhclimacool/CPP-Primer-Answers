#include <iostream>

int main() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2) {
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }
    int val = v1;
    while (val <= v2) {
        std::cout << val << " ";
        ++val;
    }
    std::cout << std::endl;
    return 0;
}
