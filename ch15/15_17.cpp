#include <iostream>
#include <string>

using namespace std;

class Quote{
public:
	Quote() = default;
	Quote(const string &book, double salesprice):bookNo(book), price(salesprice){}

	string isbn() const {return bookNo; }

	virtual double net_price(size_t n) const {
		return price * n;
	}

	virtual void debug() const {
		cout << bookNo << " : " << price;
	}

	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

// 虚基类（即含有纯虚函数的类，不能定义虚基类的对象）
class Disc_Quote : public Quote{
public:
	Disc_Quote() = default;
	Disc_Quote(const string &name, double pri, size_t qt, double dis):Quote(name, pri),quantity(qt), discount(dis){}
	// 纯虚函数，=0只能在类内部声明，可以定义它，但只能在类外部定义
	virtual double net_price(size_t n) const = 0;
	virtual void debug() const override{
		// 一定要加上作用域运算符，否则就成了无限递归
		Quote::debug();
		cout << " " << quantity << discount;
	}
	// 由于子类需要访问这些成员，因此不能为private
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_Quote : public Disc_Quote{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string &name, double pri, size_t qt, double dis):Disc_Quote(name, pri, qt, dis){}
	virtual double net_price(size_t n) const override final{
		if(n > quantity)
			return n * (1 - discount) * price;
		else
			return n * price;
	}
	virtual void debug() const override final{
		Disc_Quote::debug();
	}
};


int main(){
	Bulk_Quote quote("C++ Primer 5th ed.", 99.80, 10, 0.11);
	Quote *qt = &quote;
	qt->debug();
	cout << "quote ok" << endl;
}
