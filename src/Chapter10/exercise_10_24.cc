#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main() {
    vector<int> ivec{1,2,3,4,5,6,7,8,9,0};
    string sval = "hello";
    auto it = partition(ivec.begin(), ivec.end(), bind(check_size, sval, _1));
    cout << *it << endl;

    return 0;
}
