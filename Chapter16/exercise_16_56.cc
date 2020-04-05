#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string debug_rep(const T &t) {
  ostringstream oss;
  oss << t;
  return oss.str();
}

template <typename T>
string debug_rep(T *p) {
  ostringstream oss;
  oss << "pointer: " << p;
  if (p) 
    oss << " " << debug_rep(*p);
  else
    oss << " null pointer";
  return oss.str();
}

string debug_rep(const string &s) {
  return '"' + s + '"';
}

string debug_rep(char *p) {
  cout << "char *p" << endl;
  return debug_rep(string(p));
}

string debug_rep(const char *p) {
  cout << "const char *p" << endl;
  return debug_rep(string(p));
}

template<typename T>  
ostream &print(ostream &os, const T &t){
  return os << t;
}

template<typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &...rest) {
  os << "sizeof paramter package : " << sizeof...(rest) << " ";
  os << t << "\n";
  return print(os, rest...);
}

template <typename ... Args>
ostream &errorMsg(ostream &os, const Args ... args) {
  return print(os, debug_rep(args)...);
}

int main() {
  int a = 42; const char *cp = "fine by me"; string s = "not"; double d = 3.14;
  errorMsg(cout, a, cp, s, d);
}
