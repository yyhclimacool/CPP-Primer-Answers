#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int compare(const T &lhs, const T &rhs) {
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 1;
    return 0;
}

int main() {
    cout << "compare(12, 9): " << compare(12, 9) << endl;
    vector<int> vec1{1,2,3}, vec2{1,2,4};
    cout << "compare(vec1, vec2): " << compare(vec1, vec2) << endl;
}
