#include <iostream>
#include <string>
#include <unordered_set>

template<typename T> struct hash;

class SalesData {
    friend std::ostream &operator<<(std::ostream &, const SalesData &);
    friend bool operator==(const SalesData &, const SalesData &);
    friend class ::std::hash<SalesData>;
public:
    SalesData():bookNo(""), units_sold(0), revenue(0.0) {}
    SalesData(const std::string &name, unsigned sold, double p):
        bookNo(name),
        units_sold(sold),
        price(p),
        revenue(units_sold * price) {}
private:
    std::string bookNo;
    unsigned units_sold;
    double price;
    double revenue;
};

namespace std {
    template<>
    struct hash<SalesData> {
        using result_type = size_t;
        using argument_type = SalesData;

        size_t operator()(const SalesData &item) const {
            return hash<string>()(item.bookNo) ^
                hash<unsigned>()(item.units_sold) ^
                hash<double>()(item.revenue);
        }
    };
} // namespace std

std::ostream &operator<<(std::ostream &os, const SalesData &item) {
    return os << "BookNo:" << item.bookNo 
        << ", sold:" << item.units_sold 
        << ", revenue:" << item.revenue;
}

bool operator==(const SalesData &lhs, const SalesData &rhs) {
    return lhs.bookNo == rhs.bookNo &&
        lhs.units_sold == rhs.units_sold &&
        lhs.revenue == rhs.revenue;
}

int main() {
    SalesData sd("book1", 10, 2.99);
    std::cout << sd << std::endl;

    std::unordered_set<SalesData> dat;
    dat.insert(sd);
    std::cout << "set.size() = " << dat.size() << std::endl;
}
