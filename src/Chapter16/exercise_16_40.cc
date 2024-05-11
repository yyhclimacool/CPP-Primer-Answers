#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Value {
  friend Value operator+(const Value &, int );
public:
  Value() = default;
  Value(const Value &rhs) { 
    cout << "Calling Copy Constructor..." << endl;
  }
  ~Value() = default;
};

Value operator+(const Value &v, int i) {
  (void)i;
  return v;
}

// It's legal
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
  return *beg;
}

int main() {
  std::vector<Value> vals(10);
  auto val = fcn3(vals.begin(), vals.end());
}
