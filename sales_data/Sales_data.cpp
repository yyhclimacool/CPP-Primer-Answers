#include "Sales_data.h"

using namespace std;

Sales_data::Sales_data(istream &is){
	double price;
	is >> bookNo >> units_sold >> price;
	if(is)
		revenue = units_sold * price;
	else{
		bookNo = string();
		units_sold = 0;
		revenue = 0.0;
	}
}

ostream &operator<<(ostream &os, const Sales_data &rhs){
	os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
	return os;
}

istream &operator>>(istream &is, Sales_data &rhs){
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if(is)
		rhs.revenue = rhs.units_sold * price;
	else
		rhs = Sales_data();
	return is;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs){
	return lhs.bookNo == rhs.bookNo &&
			lhs.units_sold == rhs.units_sold &&
			lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs){
	return !(lhs == rhs);
}

Sales_data::operator string() const{
     return bookNo;
}

Sales_data::operator double() const{
    return revenue;
}
