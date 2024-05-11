#include <iostream>

using namespace std;

template<typename T, typename U, typename V>
void f1(T, U, V);

template<typename T>
T f2(const T &t) {
  return t;
}

template<typename T>
T f3(T t, unsigned int *p) {
  cout << *p << endl;
  delete p;
  return t;
}

template<typename T> void f4(T t1, T t2) {
  cout << t1 + t2 << endl; 
}

typedef char Ctype;
template<typename Ctype>
Ctype f5(Ctype a) {
  return a;
}

template<typename T, typename U, typename V>
void f1(T t, U u, V v) {
  cout << t << u << v << endl;
}

int main() {
  f1(1,2,3);
  cout << f2(std::string("fine")) << endl;
  unsigned *p = new unsigned(43);
  cout << f3(3.14, p) << endl;
  f4(2, 3);
  cout << f5(3.14) << endl;
}
