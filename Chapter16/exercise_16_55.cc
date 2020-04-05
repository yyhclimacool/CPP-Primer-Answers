#include <iostream>
#include <string>

using namespace std;

template <typename T> ostream &print(ostream &, const T &);

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &...rest) {
  os << "sizeof paramter package : " << sizeof...(rest) << " ";
  os << t << "\n";
  return print(os, rest...);
}

template<typename T> 
ostream &print(ostream &os, const T &t){
  return os << t;
}

int main() {
  int a = 11; double d = 3.14; string s = "fine"; long long lld = 21431234235;
  print(cout, d, s, a, lld);
  cout << endl;
}
