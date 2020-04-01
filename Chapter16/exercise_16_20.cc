#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

template<typename Container>
void print(const Container &c) {
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    cout << *it << " ";
  cout << endl;
}

int main() {
  deque<int> iq {12,23,34,45,56,67,78,89,90};
  vector<int> iv(iq.cbegin(), iq.cend());
  list<int> ilst(iv.cbegin(), iv.cend());
  print(iq);
  print(iv);
  print(ilst);
}
