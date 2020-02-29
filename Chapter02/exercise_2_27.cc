#include <iostream>

int main() {
    //int i = -1, &r = 0;
    int i = -1; const int &r = 0;

    const int i2 = i, &r1 = i;

    return 0;
}
