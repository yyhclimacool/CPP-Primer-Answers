#include <iostream>
using namespace std;

template<typename T, typename F = less<T>> bool compare(const T&l, const T&r, F f = F()) {
  if (f(l, r)) return -1;
  if (f(r, l)) return 1;
  else return 0;
}

int main() {
  // 引用形参不会将数组转换成指针
  //compare("hi", "world");
  //compare("bye", "dad");
  compare(12, 2);
}
