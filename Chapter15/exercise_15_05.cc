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

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc) 
        : Quote(book, p), min_qty(qty), discount(disc) { }
    double net_price(size_t cnt) const override {
        if (cnt >= min_qty) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }
    virtual void debug() const override {
        cout << "Bulk_quote: min_qty = " << min_qty << ", discount = " << discount << endl;
    }

    virtual Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    virtual Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

int main() {
  Quote quote("book1", 2.99);
  print_total(cout, quote, 10);

  Bulk_quote bulk("book2", 3.99, 10, 0.1);
  print_total(cout, bulk, 12);
}

