#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &e : vi)
        cout << e << '\t';
    cout << endl;
    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }
    for (auto &e : vi)
        cout << e << '\t';
    cout << endl;

    return 0;
}
