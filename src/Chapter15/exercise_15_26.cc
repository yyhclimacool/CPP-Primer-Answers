#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Quote {
public:
  Quote() = default;
  Quote(const string &b, double p)
    : price(p), bookno(b) {}

  Quote(const Quote &) = default; // 编译器合成的版本即可
  //Quote(Quote &&) = default; // 编译器合成的版本为我们逐成员移动

  // 这里为了看出来使用了移动构造函数，我们自己定义，而不用编译器合成的版本
  Quote(Quote &&rhs) : price(rhs.price), bookno(std::move(rhs.bookno)) {
    cout << __func__ << endl;
    rhs.bookno = "dummy";
  }

  Quote &operator=(const Quote &) = default; // default is OK
  Quote &operator=(Quote &&) = default; // default is OK

  virtual ~Quote() = default; // 因为有了析构函数，编译器不会为我们合成移动操作，我们需要显示声明移动操作

  std::string isbn() const { return bookno; }

  virtual double net_price(size_t n) const {
    return n * price;
  }

  virtual void debug() const {
    cout << "bookno = " << bookno << ", price = " << price << endl;
  }
protected:
  double price;
private:
  string bookno;
};

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const string &b, double p, size_t q, double c)
    : Quote(b, p), qty_(q), disc_(c) {
  }
  Disc_quote(const Disc_quote &) = default; // 让编译器为我们合成
  Disc_quote(Disc_quote &&) = default;

  Disc_quote &operator=(const Disc_quote &) = default;
  Disc_quote &operator=(Disc_quote &&) = default;

  virtual ~Disc_quote() = default;

  virtual double net_price(size_t n) const = 0;
  virtual void debug() const override {
    cout << "Disc_quote: qty_ = " << qty_ << ", disc_ = " << disc_ << endl;
    Quote::debug();
  }
protected:
  size_t qty_;
  double disc_;
private:

};

class Bulk_quote final : public Disc_quote {
public:
  Bulk_quote() = default; // This will be deleted
  Bulk_quote(const string &b, double p, size_t q, double dsc)
    : Disc_quote(b, p, q, dsc) {
  }

  Bulk_quote(const Bulk_quote &) = default;
  Bulk_quote(Bulk_quote &&) = default;

  Bulk_quote &operator=(const Bulk_quote &) = default;
  Bulk_quote &operator=(Bulk_quote &&) = default;

  virtual ~Bulk_quote() = default;
  virtual double net_price(size_t n) const override final{
    if (n > qty_)
      return n * (1 - disc_) * price;
    else
      return n * price;
  }
  virtual void debug() const override final {
    Disc_quote::debug();
  }
};

class Restric_quote final : public Disc_quote {
public:
  Restric_quote() = default;
  Restric_quote(const string &b, double p, size_t q, double dsc)
    : Disc_quote(b, p, q, dsc) {
  }
  virtual ~Restric_quote() = default;

  double net_price(size_t n) const override final {
    if (n <= qty_) 
      return n * price * (1 - disc_);
    else
      return price * qty_ * (1 - disc_) + (n - qty_) * price;
  }
  void debug() const override final {
    Disc_quote::debug();
  }
};

int main() {
  Quote *qp = new Quote("book1", 2.99);
  cout << qp->net_price(12) << endl;
  qp->debug();

  delete qp;

  shared_ptr<Quote> sp_q = make_shared<Quote>("book2", 3.99);
  cout << sp_q->net_price(10) << endl;
  sp_q->debug();

  // invalid new-expression of abstract class type ‘Disc_quote’
  //sp_q.reset(new Disc_quote("book3", 4.99, 10, 0.1));
  //cout << sp_q->net_price(10) << endl;
  //sp_q->debug();

  sp_q.reset(new Bulk_quote("book3", 4.99, 10, 0.1));
  cout << sp_q->net_price(20) << endl;
  sp_q->debug();

  sp_q.reset(new Restric_quote("book3", 5.99, 10, 0.1));
  cout << sp_q->net_price(20) << endl;
  sp_q->debug();

  Bulk_quote bq("book_to_move", 4.99, 20, .1);
  cout << "-------------------------------" << endl;
  bq.debug();
  cout << "-------------------------------" << endl;

  Bulk_quote bq2(std::move(bq));
  cout << "-------------------------------" << endl;
  bq.debug();
  cout << "-------------------------------" << endl;
}
