#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void reverse_print_vec(const vector<int> &vec) {
    if (vec.empty())
        return;
    auto it = vec.cend() - 1;
    while (it != vec.cbegin()) {
        cout << *(--it) << " ";
    }
    cout << endl;
}

int main() {
    vector<int> ivec{12, 23, 34, 45, 56, 67, 78, 89, 90};
    reverse_print_vec(ivec);
}
