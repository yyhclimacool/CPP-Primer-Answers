#include <iostream>
#include <string>
#include <vector>

using namespace std;

// It's legal
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
  return *beg;
}

int main() {
  vector<int> ivec{1,2,3,4,5,6,7};
  int ival = fcn3(ivec.begin(), ivec.end());
  cout << ival << endl;
}
