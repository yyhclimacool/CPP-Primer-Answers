#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec(10, 42);
    int ia[] = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    fill_n(ivec.begin(), ivec.size(), 0);
    for (auto &e : ivec)
        cout << e << '\t';
    cout << endl;

    fill_n(begin(ia), sizeof(ia) / sizeof(*ia), 8);

    for (size_t i = 0; i != sizeof(ia) / sizeof(*ia); ++i)
        cout << ia[i] << '\t';
    cout << endl;

    return 0;
}
