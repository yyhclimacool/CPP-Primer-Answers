#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec{12, 23, 34, 45, 56, 67, 78, 89, 90};
    copy(ivec.crbegin(), ivec.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
