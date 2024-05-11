#include <iostream>

using namespace std;

template<typename T> T f1(T t1, T t2) {
  (void)t1;
  (void)t2;
}

template<typename T1, typename T2> void f2(T1 t1, T2 t2) {
  cout << t1 << ", " << t2 << endl;
}

int main() {
  int i = 0, j = 42, *p1 = &i, *p2 = &j;
  const int *cp1 = &i, *cp2 = &j;

  f1(p1, p2);     // T = int *&
  f2(p1, p2);     // T1 = T2 = int *&
  f1(cp1, cp2);   // T = const int *&
  f2(cp1, cp2);   // T1 = T2 = const int *&
  // f1(p1, cp1); // ERROR: int *& <==> const int *&
  f2(p1, cp1);    // T1 = int *&, T2 = const int *&
}
