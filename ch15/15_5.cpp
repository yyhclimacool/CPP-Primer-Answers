#include <iostream>
#include <string>

using namespace std;

class Quote{
public:
	Quote() = default;
	Quote(const string &book, double p):bookNo(book), price(p){}
	string isbn() const { return bookNo;}
	virtual double net_price(size_t n) const {
		return n * price;
	}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price;
};

class Bulk_Quote final : public Quote {
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string &book, double p, size_t qty, double disc):Quote(book, p), min_qty(qty), discount(disc){};
	double net_price(size_t n) const{
		if (n >= min_qty)
			return n * (1 - discount) * price;
		else
			return n * price;
	}
	~Bulk_Quote() = default;
private:
	size_t min_qty;
	double discount;
};

double print_total(ostream &os, const Quote &item, size_t n){
     double ret = item.net_price(n);
     os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
     return ret;
}

int main(){
    Quote q("book1", 12.99);
    Bulk_Quote bq("book2", 13.99, 10, 0.2);
    auto res = print_total(cout, q, 10);
    res = print_total(cout, bq, 20);
    return 0;
}
