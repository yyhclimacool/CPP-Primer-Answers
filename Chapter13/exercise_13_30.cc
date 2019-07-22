#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*(p.ps))), i(p.i) { cout << "Copy Ctor" << endl; }
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

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "hasptr.swap" << endl;
}

int main() {
    HasPtr p1("fine");
    HasPtr p2("done");

    swap(p1, p2);

    cout << p1.getstr() << endl;
}
