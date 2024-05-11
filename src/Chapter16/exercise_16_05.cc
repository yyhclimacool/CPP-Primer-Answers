#include <iostream>

using namespace std;

template<typename T, size_t N>
void print(T (&arr)[N]) {
  for (const auto &e : arr) 
    cout << e << " ";
  cout << endl;
}

int main() {
  int ia[10] = {1,2,3,4,5,6,7,8,9,0};
  char str[12] = "abc";

  print(ia);
  print(str);
}
