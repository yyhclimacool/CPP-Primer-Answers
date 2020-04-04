#include <iostream>

using namespace std;

template<typename T> void g(T val) {
  cout << val << endl;
}

int main() {
  int i = 0;
  const int ci = i;

  g(i); // T = int , val = int 
  g(ci); // T = int , val = int 
  g(i * ci); // T = int, val = int 
}
