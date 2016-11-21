#include <iostream>

#ifndef _HASPTRV1_HPP_
#define _HASPTRV1_HPP_

using namespace std;

// The behavior looks like a pointer
class HasPtrV1{
	public:
	HasPtrV1(const string &str = string()):ps(new string(str)), i(0), use(new size_t(1)){}
	HasPtrV1(const HasPtrV1 &rhs):ps(rhs.ps), i(rhs.i), use(rhs.use){++*use;}
	HasPtrV1 &operator=(const HasPtrV1 &rhs){
		++*rhs.use;
		if(--*use == 0){
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtrV1(){
		if(--*use == 0){
			delete ps;
			delete use;
		}
	}
	private:
		string *ps;
		int i;
		size_t *use;
};

#endif