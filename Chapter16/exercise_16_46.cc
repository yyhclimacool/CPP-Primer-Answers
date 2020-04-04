#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

// 自己实现std::move

template <typename T>
typename remove_reference<T>::type &&Move(T &&val) {
  return static_cast<typename remove_reference<T>::type &&>(val);
}

int main() {
  string s1 = "fine";
  string s2(Move(s1));
  cout << s2 << endl;
  cout << s1 << endl; // 输出为空
}
