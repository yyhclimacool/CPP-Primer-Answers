#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		string getName() const { return name;}
		string getAddress() const { return address;}
	private:
		string name;
		string address;
}

#endif