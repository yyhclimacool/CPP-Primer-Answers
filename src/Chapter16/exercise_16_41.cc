#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs) {
  return lhs+rhs;
}

int main() {
  auto val = sum(1456789123456789123456789, 1289123456789123456789);
  //cout << val << endl;
}
