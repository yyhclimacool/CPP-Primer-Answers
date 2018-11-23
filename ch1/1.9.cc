#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int init = 50;
    while (init <= 100) {
        sum += init;
        ++init;
    }
    std::cout << "Sum = " << sum << std::endl;
}
