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

int main() {
  string s{"test string"};
  cout << debug_rep(s) << endl;
  cout << debug_rep(&s) << endl; // 两个候选实例，其中一个是精确匹配

  const string s2{s};
  cout << debug_rep(&s2) << endl;

  cout << debug_rep(s) << endl;
  cout << debug_rep("hello test string") << endl;
}
