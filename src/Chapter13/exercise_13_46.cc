#include <iostream>
#include <vector>

using namespace std;

int f() {
    return 42;
}

int main() {
    vector<int> vi(100);

    int &&r1 = f();
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f();

    cout << "&&r1   = " << r1 << endl;
    cout << " &r2   = " << r2 << endl;
    cout << " &r3   = " << r3 << endl;
    cout << "&&r4   = " << r4 << endl;
    
    r3 = 100;
    cout << "After r3 = 100 : " << endl;
    cout << "&&r1   = " << r1 << endl;
    cout << " &r3   = " << r3 << endl;
}
