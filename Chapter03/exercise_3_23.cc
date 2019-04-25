#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec(10, 42);

    for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
        *it = 2 * (*it);
    for (const auto &val : ivec)
        cout << val << '\t';
    cout << endl;
}
