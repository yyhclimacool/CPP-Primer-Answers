#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ia[10] = {};
    for (size_t i = 0; i < 10; ++i)
        ia[i] = i;

    int ia2[10] = {};
    for (size_t i = 0; i < 10; ++i)
        ia2[i] = ia[i];

    for (auto i : ia2)
        cout << i << " ";
    cout << endl;

    // Using vector
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ivec2 = ivec;
    for (auto &e : ivec2)
        cout << e << " ";
    cout << endl;

}
