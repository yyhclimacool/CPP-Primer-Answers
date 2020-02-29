#include <iostream>

int main() {
    int i = -1; const int &r = 0;
    int * const p2 = &i;
    const int i1 = -1, &r1 = 0;
    const int * const p3 = &i1;
    const int * p4 = &i1;
    const int & r2 = 0;
    const int i2 = i, &r3 = i;
    return 0;
}
