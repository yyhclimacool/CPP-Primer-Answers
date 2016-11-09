#ifndef _SALES_DATA_HPP_
#define _SALES_DATA_HPP_

#include <iostream>
#include <string>

using namespace std;

class Sales_data{
	public:
		/*
		 * 默认情况下this指针的类型为：Sales_data * const
		 * 这种情况下这个函数就不能被具有const属性的对象调用了
		 * const提高了函数的灵活性
		 */
		string isbn() const { return bookNo;}
		Sales_data &combine(const Sales_data &rhs);
		double avg_price() const;
	private:
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &input(istream &, Sales_data &);

#endif