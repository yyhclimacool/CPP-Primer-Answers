#include <iostream>
#include <memory>
#include <string>

using namespace std;

const size_t BUF_SIZE = 10;

int main() {
    allocator<string> alloc;
    string *const p = alloc.allocate(BUF_SIZE);
    string *q = p;
    string str;
    while (cin >> str && q != (p + BUF_SIZE)) {
        alloc.construct(q++, str);
    }

    cout << "Total " << q - p << " element(s)" << endl;

    // destroy in reverse order
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, BUF_SIZE);
}
