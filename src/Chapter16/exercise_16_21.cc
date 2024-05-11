#include <iostream>
#include <memory>

using namespace std;

class DebugDelete {
public:
  DebugDelete(ostream &o = clog) : os(o) {
    cout << "Calling DebugDelete(ostream &o)" << endl;
  }
  template<typename T> void operator()(T *p) {
    os << "Calling delete " << p << endl;
    delete p;
  }

private:
  ostream &os;
};

int main() {
  unique_ptr<string, DebugDelete> up(new string("I'm newed"), DebugDelete());
  {
    auto local_up = std::move(up);
  }
}
