#include <iostream>
#include <vector>

using namespace std;

class Sales_data {
public:
  Sales_data(const string &book) : bookno(book) {}
  string bookno;
  size_t units_sold = 0;
  double price = 0.0;
};

bool operator<(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.bookno < rhs.bookno;
}

template <typename T>
int compare(const T &lhs, const T &rhs) {
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 1;
    return 0;
}

/* 
 * CAUTION: compile error
 *
 */
int main() {
    Sales_data data1("book1"), data2("book2");
    cout << compare(data1, data2) << endl;
}
