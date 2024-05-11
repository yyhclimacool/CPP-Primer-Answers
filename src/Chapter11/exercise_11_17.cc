#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
    multiset<string> sms = {"where", "there", "is", "a", "wish", "there", "is", "a", "way"};
    vector<string> svec = {"where", "there", "is", "a", "wish", "there", "is", "a", "way"};
    multiset<string> c;
    vector<string> v;

    copy(svec.begin(), svec.end(), inserter(c, c.end()));
    copy(c.cbegin(), c.cend(), ostream_iterator<string>(cout, "\t"));
    cout << endl;

    c.clear();

    // ERROR: no push_back also no push_front
    // copy(svec.begin(), svec.end(), back_inserter(c));
    
    copy(sms.cbegin(), sms.cend(), inserter(v, v.end()));
    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\t"));
    cout << endl;

    v.clear();

    copy(sms.begin(), sms.end(), back_inserter(v));
    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\t"));
    cout << endl;
}
