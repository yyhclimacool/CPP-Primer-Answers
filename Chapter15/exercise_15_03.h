#pragma once

#include <iostream>
#include <string>

using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &str, double sales_price) : bookNo(str), price(sales_price) {}
    virtual ~Quote() = default;  // 对析构函数进行动态绑定

    string isbn() const { return bookNo; }
    // 派生类负责改写并使用不同的算法
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const {
        cout << "Quote : bookNo = " << bookNo << ", price = " << price << endl;
    }

    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() && { return new Quote(std::move(*this)); }
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total(std::ostream &os, const Quote &q, size_t n) {
    auto ret = q.net_price(n);
    os << q.isbn() << ", " << ret << endl;
    return ret;
}

