#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec{begin(ia), end(ia)};
    list<int> ilst(begin(ia), end(ia));

    for (auto it = ilst.begin(); it != ilst.end();) {
        if (*it % 2)
            it = ilst.erase(it);
        else
            ++it;
    }

    for (auto it = ivec.begin(); it != ivec.end(); ) {
        if (*it % 2 == 0)
            it = ivec.erase(it);
        else
            ++it;
    }

    for (auto e : ivec)
        cout << e << "\t";
    cout << endl;

    for (auto e : ilst)
        cout << e << "\t";
    cout << endl;

    return 0;
}
