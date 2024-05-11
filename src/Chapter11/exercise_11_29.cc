#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    std::multiset<int> ms = {1,1,2,3,3,5,6,8,5,3,6,8,4,9,0,3};
    std::copy(ms.cbegin(), ms.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    std::multiset<int>::iterator l_it = ms.lower_bound(3);
    std::multiset<int>::iterator u_it = ms.upper_bound(3);
    std::copy(l_it, u_it, ostream_iterator<int>(cout, " "));
    cout << endl;

    l_it = ms.lower_bound(7);
    u_it = ms.upper_bound(7);
    if (l_it == u_it)
        cout << "ms.lower_bound(7) == ms.upper_bound(7)" << endl;
    auto res = ms.equal_range(7);
    if (res.first == res.second)
        cout << "res.first == res.second" << endl;
}
