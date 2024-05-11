#include <iostream>

using namespace std;

template <typename T> void f(T t) {
  cout << __func__ << " : " << t << endl;
}

template <typename T> void f(const T *p) {
  cout << __func__ << " : " << " pointer = " << p << " content = " << *p << endl;
}

template <typename T> void g(T t) {
  cout << __func__ << " : " << t << endl;
}

template <typename T> void g(T *p) {
  cout << __func__ << " : " << " pointer = " << p << " content = " << *p << endl;
}

int main() {
  int i = 42, *p = &i;
  const int ci = 0, *p2 = &ci;

  g(42);
  g(p);
  g(ci);
  g(p2);

  f(42); f(p); f(ci); f(p2);
}
