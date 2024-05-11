#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

template<typename Container>
void print(const Container &c) {
  for (typename Container::size_type i = 0; i != c.size(); ++i) 
    cout << c[i] << " ";
  cout << endl;
}

int main() {
  deque<int> iq {12,23,34,45,56,67,78,89,90};
  vector<int> iv(iq.cbegin(), iq.cend());
  print(iq);
  print(iv);
}
