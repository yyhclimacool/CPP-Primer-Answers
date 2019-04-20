#include <iostream>

int main() {
    int i, * const cp = &i;
    int *p1, *const p2 = p1;
    const int ic = 42, &r = ic;
    const int *const p3 = nullptr;
    const int *p;

    return 0;
}
