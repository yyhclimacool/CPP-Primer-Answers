#include <iostream>

using namespace std;

int f(int val, int val2) {
    auto lam = [val](int a) { return val + a; };
    return lam(val2);
}

int main() {
    cout << f(10, 42) << endl;
}
