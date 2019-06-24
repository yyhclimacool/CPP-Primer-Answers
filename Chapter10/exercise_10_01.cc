#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> ivec{1, 23, 984, 234, 5, 5, 5, 1, 2, 6, 23, 99, 5};

    cout << "5  : " << count(ivec.begin(), ivec.end(), 5) << endl;
    cout << "23 : " << count(ivec.begin(), ivec.end(), 23) << endl;

    return 0;
}
