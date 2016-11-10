#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <iostream>
#include <string>

using namespace std;

class Person;

istream &read(istream &, Person &);
ostream &print(ostream &, const Person &);

class Person{
	public:
		Person() = default;
		Person(const string &n, const string &ad):name(n), address(ad) {}
		Person(istream &is){ read(is, *this);}
		string getName() const { return name;}
		string getAddress() const { return address;}
	// private:
		string name;
		string address;
};

istream &read(istream &is, Person &rhs){
	is >> rhs.name >> rhs.address;
	return is;
}

ostream &print(ostream &os, const Person &rhs){
	os << rhs.name << rhs.address;
	return os;
}

#endif