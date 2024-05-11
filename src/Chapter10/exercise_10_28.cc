#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iterator>

using namespace std;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> vec2;
    ostream_iterator<int> os(cout);

    copy(ivec.begin(), ivec.end(), back_inserter(vec2));
    copy(vec2.cbegin(), vec2.cend(), os);
    cout << endl;

    vec2.clear();

    copy(ivec.begin(), ivec.end(), front_inserter(vec2));
    copy(vec2.cbegin(), vec2.cend(), os);
    cout << endl;

    vec2.clear();

    copy(ivec.begin(), ivec.end(), inserter(vec2, vec2.begin()));
    copy(vec2.cbegin(), vec2.cend(), os);
    cout << endl;
}
