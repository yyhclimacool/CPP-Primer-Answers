#include <iostream>

using namespace std;

int main() {
    int ival = 10, ival2 = 42;
    int *piv = &ival;
    cout << *piv << endl;
    piv = &ival2;
    cout << *piv << endl;
    *piv = 100;
    cout << *piv << endl;
}
