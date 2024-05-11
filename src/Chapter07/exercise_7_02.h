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
