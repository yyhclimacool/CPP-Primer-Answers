#include <iostream>

void swap_pointers(int *&lhs, int *&rhs) {
    int *tmp = rhs;
    rhs = lhs;
    lhs = tmp;
}

int main() {
    int a = 12, b = 15;
    int *ap = &a, *bp = &b;
    std::cout << *ap << ", " << *bp << std::endl;
    swap_pointers(ap, bp);
    std::cout << *ap << ", " << *bp << std::endl;
}
