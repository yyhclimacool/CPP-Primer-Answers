#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> vec2;

    copy(ivec.begin(), ivec.end(), back_inserter(vec2));
    for (auto e : vec2)
        cout << e << ' ';
    cout << endl;

    vec2.clear();

    copy(ivec.begin(), ivec.end(), front_inserter(vec2));
    for (auto e : vec2)
        cout << e << ' ';
    cout << endl;

    vec2.clear();

    copy(ivec.begin(), ivec.end(), inserter(vec2, vec2.begin()));
    for (auto e : vec2)
        cout << e << ' ';
    cout << endl;
}
