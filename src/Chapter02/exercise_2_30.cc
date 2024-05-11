#include <iostream>

int main() {
    const int v2 = 0;   // top-level-const
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;

    // p2 : low-level-const
    // p3 : both top and low
    // r2 : low-level-const
    const int *p2 = &v2, *const p3 = &v1, &r2 = v2;

    return 0;
}
