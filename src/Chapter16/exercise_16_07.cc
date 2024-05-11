#include <iostream>

using namespace std;

template<typename T, size_t N>
constexpr size_t size(T (&arr)[N]) {
  (void) arr;
  return N;
}

int main() {
  int ia[]{1,2,3,4};
  cout << size(ia) << endl;
  const char str[] = "finebyme";
  cout << size(str) << endl;
}
