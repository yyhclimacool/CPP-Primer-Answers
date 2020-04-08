#include <iostream>
#include <random>

using namespace std;

int main() {
  int ival;
  cout << "Input a seed:\t" << endl;
  cin >> ival;
  std::default_random_engine e(ival);
  int min = 0, max = 0;
  cout << "Input distribution range: \t" << endl;
  cin >> min >> max;
  std::uniform_int_distribution<unsigned> d(min, max);

  for (int i = 1; i != 101; ++i) {
    cout << d(e) << "\t";
    if (i % 10 == 0)
      cout << endl;
  }
  cout << endl;
}
