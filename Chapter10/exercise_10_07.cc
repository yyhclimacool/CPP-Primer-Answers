#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<int> ivec;
    list<int> lst;
    int i;
    while (cin >> i)
        ivec.push_back(i);
    copy(ivec.cbegin(), ivec.cend(), back_inserter(lst));

    ////////////////////////////////////////
    vector<int> vec;
    vec.reserve(10);
    fill_n(vec.begin(), 10, 0);
}
