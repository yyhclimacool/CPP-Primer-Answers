#include <memory>
#include <iostream>

using namespace std;

int main() {
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    using intP = unique_ptr<int>;

    intP p2(pi2); // OK
    {
        // intP p0(ia);
        // intP p1(pi); // undefined behaviour, core dump
        // intP p3(&ix); // undefined behaviour, core dump
        intP p4(new int(1024));
        intP p5(p2.get()); // Danger
    }
    cout << *p2 << endl; // undefined behaviour
    return 0;
}
