#include <set>
#include <string>
#include "../Chapter07/Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);

    bookstore.emplace("0000-000-9999");
    bookstore.emplace("1111-000-1111");

    for (const auto &e : bookstore) {
        print(cout, e);
        cout << endl;
    }
}
