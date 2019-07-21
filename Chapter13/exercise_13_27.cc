#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend ostream &operator<<(ostream &os, const HasPtr &p);
    public:
        HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
        HasPtr(const HasPtr &p):
            ps(p.ps), i(p.i), use(p.use) { ++(*use); }
        HasPtr &operator=(const HasPtr &p) {
            ++*p.use;
            if (--*use == 0) {
                delete ps;
                delete use;
            }
            ps = p.ps;
            i = p.i;
            use = p.use;
            return *this;
        }
        ~HasPtr() {
            if (--*use == 0) {
                delete ps;
                delete use;
            }
        }

    private:
        string *ps;
        int i;
        size_t *use;
};

ostream &operator<<(ostream &os, const HasPtr &p) {
    os << "<" << *p.ps << "> have " << *p.use << " users"; 
    return os;
}

int main() {
    HasPtr p1("a string");
    HasPtr p2(p1);
    cout << p2 << endl;
}
