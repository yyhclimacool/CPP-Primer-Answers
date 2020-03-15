#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
    list<int> ilst(ivec.crbegin() + 3, ivec.crbegin() + 7);
    copy(ilst.cbegin(), ilst.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
