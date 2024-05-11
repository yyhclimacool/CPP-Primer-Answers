#include <iostream>
#include <functional>
#include <vector>

using namespace std;

std::modulus<int> mod;

int main() {
  vector<int> ivec = {12,2,3,5,7,8,9};

  int ival;
  cout << "Input a int value:" << endl;
  cin >> ival;
  
  bool done = true;
  for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
    if (mod(ival, *it) != 0) {
      cout << *it << endl;
      done = false;
      break;
    }
  }
  cout << done << endl;
}
