#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    vector<int> ivec(10, 42);
    cout << accumulate(ivec.begin(), ivec.end(), 0) << endl;
    return 0;
}
