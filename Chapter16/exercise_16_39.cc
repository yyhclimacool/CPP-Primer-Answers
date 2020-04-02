#include <iostream>
using namespace std;

template<typename T>
bool compare(const T &lhs, const T &rhs) {
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}

int main() {
  // 比较没有意义
  cout << compare<const char *>("fine", "me") << endl;
}
