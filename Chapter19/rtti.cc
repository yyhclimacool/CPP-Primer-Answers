#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Base {
  friend bool operator==(const Base &lhs, const Base &rhs);
public:
  Base() = default;
  Base(const string &s) : content(s) {}
protected: 
  std::string content;
private:
  virtual bool equal(const Base &other) const {
    cout << "calling Base::equal ..." << endl;
    return content == other.content;
  }
};

class Derived : public Base {
public:
  Derived() = default;
  Derived(const string &s, int i) : Base(s), ival(i) {}
private:
  int ival = 0;
  virtual bool equal(const Base &other) const {
    cout << "calling Derived::equal ..." << endl;
    const Derived &d = dynamic_cast<const Derived &>(other);
    return content == d.content && ival == d.ival;
  }
};

bool operator==(const Base &lhs, const Base &rhs) {
  return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main() {
  Base b1("abc");
  Base b2("abc");
  Base b3("abcd");

  if (b1 == b2) cout << "b1 == b2" << endl;
  if (b1 == b3) cout << "b1 == b3" << endl;
  else cout << "b1 != b3" << endl;

  Derived d1("bac", 42);
  Derived d2("bac", 42);
  Derived d3("bac", 43);
  Derived d4("abc", 43);

  if (d1 == d2) cout << "d1 == d2" << endl;
  else cout << "d1 != d2" << endl;

  if (d2 == d3) cout << "d2 == d3" << endl;
  else cout << "d2 != d3" << endl;

  if (d4 == b1) cout << "b1 == d4" << endl;
  else cout << "b1 != d4" << endl;

  cout << typeid(b1).name() << endl;
  cout << typeid(d1).name() << endl;
}
