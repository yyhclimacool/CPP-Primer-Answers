#include <string>
#include <iostream>

using namespace std;

class Base {
public:
    Base(int ival, char ch) : prot_mem(ival), priv_mem(ch) { }
    void pub_mem() const { cout << "Base : prot_mem = " << prot_mem << ", priv_mem = " << priv_mem << endl; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    Pub_Derv(int ival, char ch) : Base(ival, ch) {}
    int f() { cout << "Pub_Derv : Base.prot_mem = " << prot_mem << endl; return prot_mem; }
    char g() { //cout << "Base.priv_mem = " << priv_mem << endl; return priv_mem;
        cout << "Can't access Base.priv_mem ! cause it's private member of Base." << endl;
        return '\0';
    }
};

struct Prot_Derv : protected Base {
  Prot_Derv(int ival, char ch) : Base(ival, ch) {}
};

struct Priv_Derv : private Base {
    Priv_Derv(int ival, char ch) : Base(ival, ch) {}
    int f1() const { cout << "Priv_Derv : Base.prot_mem = " << prot_mem << endl; return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
    Derived_from_Public(int ival, char ch) : Pub_Derv(ival, ch) {}
    int use_base() { cout << "Derived_from_Public.Pub_Derv.Base.prot_mem = " << prot_mem << endl; return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
    Derived_from_Private(int ival, char ch) : Priv_Derv(ival, ch) {}
    // 错误: Base::prot_mem在Priv_Derv中是private的
    int use_base () const { //return prot_mem; 
        cout << "Can't access protected member of Base, case Priv_Derv is private derived from Base." << endl;
        return 0;
    }
};

int main() {
    Pub_Derv d1(42, 'c');
    Priv_Derv d2(43, 'd');
    Prot_Derv d3(44, 'e');

    Base *p = &d1;
    // p = &d2; // ‘Base’ is an inaccessible base
    // p = &d3; // ‘Base’ is an inaccessible base

    Derived_from_Public dd1(45, 'f');
    Derived_from_Private dd2(46, 'g');

    p = &dd1;
    // p = &dd2; // ‘Base’ is an inaccessible base
}
