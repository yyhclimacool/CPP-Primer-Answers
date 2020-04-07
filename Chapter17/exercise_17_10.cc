#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
  bitset<32> bv;
  int ia[] = {1, 2, 3, 5, 8, 13, 21};
  std::for_each(begin(ia), end(ia), [&](int ival) { bv.set(ival, 1); });
  cout << bv << endl;

  bitset<32> bv2;
  cout << bv2.set() << endl;
}
