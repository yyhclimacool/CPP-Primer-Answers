#include <iostream>

using namespace std;

template<typename T> T calc(T t, int i) {
  cout << t << ", " << i << endl;
  return t;
}

template<typename T> T fcn(T t1, T t2) {
  return t1 + t2;
}

int main() {
  double d = 0.0;
  float f{0.0};
  char c{'a'};

  calc(c, 'c');
  calc(d, f);
  fcn(c, 'c');
  //fcn(d, f);
}
