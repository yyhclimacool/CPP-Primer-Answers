#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    list<int> ilst{12, 23, 34, 45, 56, 67, 78, 89, 0, 90};
    auto it = find(ilst.crbegin(), ilst.crend(), 0);
    if (it == ilst.crend())
        cout << "Reverse find 0: false" << endl;
    else
        cout << "Reverse found " << *it << ": true" << endl;
}
