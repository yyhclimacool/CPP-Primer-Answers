#include <iostream>

using namespace std;

int main() {
    auto lam = [](int a, int b) { return a + b; };
    cout << lam(42, 5) << endl;
}
