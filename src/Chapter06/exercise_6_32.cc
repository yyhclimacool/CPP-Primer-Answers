#include <iostream>

int &get(int *array, int index) { return array[index]; }

int main() {
    int ia[10];
    for (int elem : ia)
        std::cout << elem << " ";
    std::cout << std::endl;

    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }

    for (int elem : ia)
        std::cout << elem << " ";
    std::cout << std::endl;
}
