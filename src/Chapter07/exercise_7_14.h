#include <string>

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &book, unsigned sold, double price) :
        bookNo(book), units_sold(sold), revenue(sold * price) {}
    Sales_data(istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &item) {
        units_sold += item.units_sold;
        revenue += item.revenue;
        return *this;
    }

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
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
