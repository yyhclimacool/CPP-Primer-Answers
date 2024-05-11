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
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote final : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const string &bookno, double p, size_t max_q, double d)
    : Quote(bookno, p), max_qty_(max_q), disc_(d) {
  }
  virtual ~Disc_quote() {
  }

  virtual double net_price(size_t n) const override {
    if (n <= max_qty_)
      return price * (1 - disc_) * n;
    else
      return (price * (1 - disc_) * max_qty_) + (price * (n - max_qty_));
  }
  virtual void debug() const override {
    cout << "Disc_quote : bookNo = " << isbn() << ", price = " << price 
      << ", max_qty_ = " << max_qty_ << ", disc_ = " << disc_ << endl;
  }
private:
  size_t max_qty_ = 0;
  double disc_ = 0.0;
};

double print_total(std::ostream &os, const Quote &q, size_t n) {
    auto ret = q.net_price(n);
    os << q.isbn() << ", " << ret << endl;
    return ret;
}

int main() {
    Quote base("book_1", 22);
    Disc_quote disc("book_3", 22, 5, 0.1);

    print_total(cout, base, 5);
    print_total(cout, disc, 4);
    print_total(cout, disc, 7);

    Quote *qp = &base;
    qp->debug();
    qp = &disc;
    qp->debug();
}
