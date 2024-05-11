#include <iostream>
#include <string>

using namespace std;

class Big {
public:
  class Small {
  public:
    Small(int i) : ival(i) {}
    int get() const { return ival; }
  private:
    int ival;
  };
  Big(int i, const string &s) : sm(i), sval(s) {}
  ostream &print(ostream &os);
private:
  Small sm;
  string sval;
};


ostream &Big::print(ostream &os) {
  os << sm.get() << ", " << sval << endl;
  return os;
}

int main() {
  Big::Small s(21);
  cout << s.get() << endl;
  Big b(42, "hello");
  b.print(cout) << endl;
}
