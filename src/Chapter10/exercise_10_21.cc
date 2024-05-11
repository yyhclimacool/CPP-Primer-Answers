#include <iostream>

using namespace std;

int f(int val) {
    auto lam = [&val] () -> bool { 
        if (val == 0) 
            return true;
        else {
            while (val > 0) --val;
            return false;
        }
    };

    lam();
}

int main() {
    cout << f(1) << endl;
    cout << f(0) << endl;

    return 0;
}
