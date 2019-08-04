#include <iostream>
#include <string>

using namespace std;

class Base {
public:
    Base(const string &name) : basename(name) {}
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};

class Derived : public Base {
public:
    Derived(const string &name, int i) : Base(name), i(i) {}
    void print(ostream &os) { Base::print(os); os << " " << i; }
private:
    int i;
};

int main() {
    Base b("kevin");
    Derived d("aero", 42);

    b.print(cout);
    cout << endl;
    d.print(cout);
    cout << endl;
}
