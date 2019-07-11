#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    multiset<string> sms = {"where", "there", "is", "a", "wish", "there", "is", "a", "will"};
    vector<string> svec = {"where", "there", "is", "a", "wish", "there", "is", "a", "will"};
    multiset<string> c;
    vector<string> v;

    copy(svec.begin(), svec.end(), inserter(c, c.end()));
    for (const auto &e : c)
        cout << e << '\t';
    cout << endl;

    c.clear();

    // ERROR: no push_back
    // copy(svec.begin(), svec.end(), back_inserter(c));
    
    copy(sms.begin(), sms.end(), inserter(v, v.end()));
    for (const auto &e : v)
        cout << e << '\t';
    cout << endl;

    v.clear();

    copy(sms.begin(), sms.end(), back_inserter(v));
    for (const auto &e : v)
        cout << e << '\t';
    cout << endl;
}
