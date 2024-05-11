#include <iostream>
#include <tuple>

using namespace std;

int main() {
  std::tuple<int, int, int> int_tuple{10, 20, 30};
  std::cout << get<0>(int_tuple) << endl;
  std::cout << get<2>(int_tuple) << endl;
}
