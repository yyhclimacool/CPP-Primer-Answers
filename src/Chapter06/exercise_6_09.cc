#include <iostream>
#include "Chapter6.h"

using namespace std;

int fact(int ival) {
    int res = 1;
    while (ival > 1) {
        res *= ival--;
    }
    return res;
}

int main() {
    cout << fact(5) << endl;
}
