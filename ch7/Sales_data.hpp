#ifndef _SALES_DATA_HPP_
#define _SALES_DATA_HPP_

#include <iostream>
#include <string>

using namespace std;

class Sales_data;

Sales_data add(const Sales_data &, const Sales_data &);
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

class Sales_data{
		friend Sales_data add(const Sales_data &, const Sales_data &);
		friend istream &read(istream &, Sales_data &);
		friend ostream &print(ostream &, const Sales_data &);
	public:
		// Sales_data() = default;
		// Sales_data(const string &str):bookNo(str), units_sold(0), revenue(0.0){}
		Sales_data(const string &str, unsigned us, double price):bookNo(str), units_sold(us), revenue(us *price){}
		// Sales_data(istream &is){read(is, *this);}
		
		/***********Delegating Constructor**************
		***********************************************/
		Sales_data():Sales_data("", 0, 0.0){ cout << "Default constructor with delegating" << endl;}
		Sales_data(const string &str):Sales_data(str, 0, 0.0) { cout << "Constructor with one string parameter using delegating" << endl;}
		Sales_data(istream &is):Sales_data(){ read(is, *this); cout << "Constructor with an istream parameter using delegating" << endl;}
		/*
		 * 默认情况下this指针的类型为：Sales_data * const
		 * 这种情况下这个函数就不能被具有const属性的对象调用了
		 * const提高了函数的灵活性
		 */
		string isbn() const { return bookNo;}
		Sales_data &combine(const Sales_data &rhs);

	private:
		double avg_price() const;
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

/*
Sales_data::Sales_data(istream &is){
	read(is, *this);
}
*/

Sales_data &Sales_data::combine(const Sales_data &rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const {
	if(units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream &os, const Sales_data &rhs){
	os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
	return os;
}

istream &read(istream &is, Sales_data &rhs){
	double price = 0.0;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	rhs.revenue = rhs.units_sold * price;
	return is;
}

#endif