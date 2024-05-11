#include <string>

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }

    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

istream &read(istream &is, Sales_data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &data) {
    os << data.bookNo << " " << data.units_sold << " " << data.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
