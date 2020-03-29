#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Quote {
public:
  Quote() = default;
  Quote(const string &b, double p)
    : price(p), bookno(b) {}
  virtual ~Quote() = default;

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
  //Disc_quote() = default;
  Disc_quote(const string &b, double p, size_t q, double c)
    : Quote(b, p), qty_(q), disc_(c) {
  }
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

  //Bulk_quote bq; // Not OK
}
