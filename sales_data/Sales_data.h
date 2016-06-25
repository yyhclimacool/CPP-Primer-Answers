#ifndef _SALES_DATA_H
#define _SALES_DATA_H

#include <string>
#include <iostream>

using namespace std;

class Sales_data{
	friend ostream &operator<<(ostream &os, const Sales_data &rhs);
	friend istream &operator>>(istream &is, Sales_data &rhs);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator!=(const Sales_data &, const Sales_data &);
public:
	Sales_data() = default;
	Sales_data(const string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(units_sold * p){}
	Sales_data(const string &s):bookNo(s){}
	Sales_data(istream &is);
	string isbn() const { return bookNo;}
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	double avg_price() const{
		return units_sold ? revenue / units_sold : 0;
	}
};

#endif // _SALES_DATA_H
