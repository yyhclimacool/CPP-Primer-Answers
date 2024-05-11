#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Itor, typename T>
Itor myfind(const Itor &beg, const Itor &end, const T &val) {
    Itor it = beg;
    for (; it != end; ++it)
        if (*it == val)
            break;
    return it;
}

int main() {
    vector<int> ivec{1,2,3,4,5,6,7,8,9};
    list<string> slst{"you" , "tell" , "me", "why"};

    cout << (myfind(ivec.begin(), ivec.end(), 7) != ivec.end()) << endl;
    cout << (myfind(slst.begin(), slst.end(), "why") != slst.end()) << endl;
    cout << (myfind(slst.begin(), slst.end(), "sky") != slst.end()) << endl;
}
