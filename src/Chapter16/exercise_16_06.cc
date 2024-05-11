#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T, size_t N>
T *Mybegin(T (&arr)[N]) {
  return &arr[0];
}

template<typename T, size_t N>
T *Myend(T (&arr)[N]) {
  return &arr[N];
}

int main() {
  int ia[] = {1,2,3,4,5,6,7,87,9};
  std::copy(Mybegin(ia), Myend(ia), ostream_iterator<int>(cout, " "));
  cout << endl;
  string str[]{"first", "second", "third"};
  std::copy(Mybegin(str), Myend(str), ostream_iterator<string>(cout, " "));
  cout << endl;
}
