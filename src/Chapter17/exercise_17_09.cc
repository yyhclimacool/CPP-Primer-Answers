#include <iostream>
#include <bitset>

using namespace std;

int main() {
  bitset<64> bitvec(32);
  bitset<32> bv(1010101);
  cout << bitvec << endl;
  cout << bv << endl;
  string bstr;
  cin >> bstr;
  bitset<8> bvs(bstr);
  cout << bvs << endl;
}
