#include <iostream>
#include <vector>

using namespace std;

template <typename T> void g(T &&val) { (void)val; vector<T> v; }

int main() {
  g(42);
  //int i = 43;
  //g(i); T = int &
}
