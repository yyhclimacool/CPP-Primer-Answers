#ifndef _HASPTR_HPP_
#define _HASPTR_HPP_

#include <iostream>

using namespace std;

// a value-like class
class HasPtr{
	public:
		friend void swap(HasPtr &lhs, HasPtr &rhs);
		HasPtr(const string &str = string()):ps(new string(str)), i(0){}
		HasPtr(const string &str, int iv): ps(new string(str)), i(iv){}
		HasPtr(const HasPtr &rhs):ps(new string(*(rhs.ps))), i(rhs.i){}
		
		HasPtr &operator=(const HasPtr &rhs){
			string *newp = new string(*rhs.ps);
			delete ps;
			ps = newp;
			i = rhs.i;
			return *this;
		}
		friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
		friend ostream & operator<<(ostream &os, const HasPtr &rhs);
		~HasPtr(){
			delete ps;
			cout << "Destructor called!" << endl;
		}
	private:
		string *ps;
		int i;
};

void swap(HasPtr &lhs, HasPtr &rhs){
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	// For debug ...
	cout << "Calling swap of HasPtr" << endl;
}

ostream & operator<<(ostream &os, const HasPtr &rhs){
	os << rhs.i << "---" << *rhs.ps;
	return os;
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs){
	return lhs.i < rhs.i ? true:false;
}

#endif