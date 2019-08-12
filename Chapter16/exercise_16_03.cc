#include <iostream>
#include <vector>

#include "../Chapter07/exercise_7_21.h"

using namespace std;

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
