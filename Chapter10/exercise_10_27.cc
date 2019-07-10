#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ivec{0, 0, 1, 2, 2, 3, 5, 4, 4, 3, 3, 6, 7, 8, 7, 7, 8, 9};
    list<int> ilst;

    unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
    for (auto e : ilst)
        cout << e << ',';
    cout << endl;

    ilst.clear();

    unique_copy(ivec.begin(), ivec.end(), front_inserter(ilst));
    for (auto e : ilst)
        cout << e << ',';
    cout << endl;

    ilst.clear();

    unique_copy(ivec.begin(), ivec.end(), inserter(ilst, ilst.begin()));
    for (auto e : ilst)
        cout << e << ',';
    cout << endl;
}
