#include <iostream>
#include <string>

using namespace std;

template <typename T, typename ... Args>
void foo(const T &t, const Args & ... rest) {
  cout << sizeof...(Args) << std::endl;
  cout << sizeof...(rest) << endl;
}

int main() {
  int a = 0; double d = 3.14; string s = "how are you";
  foo(a, d, 42, s);
  foo(s, 42, "hi");
  foo(d, s);
  foo("hi");
}
