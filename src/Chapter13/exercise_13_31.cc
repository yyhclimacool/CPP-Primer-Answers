#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &, const HasPtr &);
    friend ostream &operator<<(ostream &, const HasPtr &);
public:
    HasPtr(const string &s = string(), int ival = 0) : ps(new string(s)), i(ival) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { cout << "Copy Ctor" << endl; }
    HasPtr &operator=(const HasPtr &p) { 
        auto newp = new string(*p.ps);
        delete ps;
        ps = newp;
        i = p.i;
        cout << "copy assignment" << endl;
        return *this;
    }

    string &getstr() const { return *ps; }
private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "calling " << __func__ << endl;
}

inline bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return lhs.i < rhs.i;
}
ostream &operator<<(ostream &os, const HasPtr &rhs) {
    return os << *rhs.ps << " " << rhs.i;
}

int main() {
    std::vector<HasPtr> hpvec{HasPtr("No.32", 32), HasPtr("No.4", 4), HasPtr("No.9", 9), HasPtr("No.2", 2), HasPtr("No.56", 56)};
    // https://stackoverflow.com/questions/14212701/stdsort-does-not-always-call-stdswap
    std::sort(hpvec.begin(), hpvec.end());
    std::copy(hpvec.cbegin(), hpvec.cend(), ostream_iterator<HasPtr>(cout, "\t"));
    cout << endl;
}
