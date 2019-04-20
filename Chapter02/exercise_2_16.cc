#include <iostream>

int main() {
    int i = 0, &ri = i;
    double d = 0, &rd = d;

    rd = 3.14159;
    rd = ri;
    i = rd;
    ri = d;

    return 0;
}
