#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    friend istream &operator>>(istream &, Sales_data &);
    friend ostream &operator<<(ostream &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);

    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const Sales_data &) = default;
    Sales_data &operator=(const Sales_data &) = default;
    Sales_data &operator=(const string &str) {
        Sales_data data(str);
        *this = data;
        return *this;
    }
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
    rhs.revenue = rhs.units_sold * price;
    return is;
}

ostream &operator<<(ostream &os, const Sales_data &rhs) {
    os << rhs.bookNo << ", " << rhs.units_sold << ", " << rhs.revenue;
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data temp;
    if (lhs.bookNo != rhs.bookNo)
        return temp;
    temp.units_sold = lhs.units_sold + rhs.units_sold;
    temp.revenue = lhs.revenue + rhs.revenue;
    return temp;
}

int main() {

}
