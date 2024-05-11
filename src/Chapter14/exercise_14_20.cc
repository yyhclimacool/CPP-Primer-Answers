#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    friend istream &operator>>(istream &, Sales_data &);
    friend ostream &operator<<(ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);

    Sales_data() = default;
    Sales_data(const Sales_data &) = default;
    Sales_data &operator=(const Sales_data &) = default;
    ~Sales_data() = default;

    Sales_data &operator+=(const Sales_data &rhs) {
        if (bookNo != rhs.bookNo)
            return *this;
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    std::string bookNo;
    unsigned units_sold{0};
    double revenue{0.0};
};


istream &operator>>(istream &is, Sales_data &rhs) {
    double price = 0.0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    if (!is) rhs = Sales_data();
    else rhs.revenue = rhs.units_sold * price;
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &rhs) {
    os << rhs.bookNo << ", " << rhs.units_sold << ", " << rhs.revenue;
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data tmp = lhs;
  tmp += rhs;
  return tmp;
}

int main() {
}
