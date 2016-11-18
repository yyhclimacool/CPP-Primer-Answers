#ifndef _HASPTR_HPP_
#define _HASPTR_HPP_

#include <iostream>

using namespace std;

class HasPtr{
	public:
		HasPtr(const string &str = string()):ps(new string(str)), i(0){}
		HasPtr(const HasPtr &rhs):ps(new string(*(rhs.ps))), i(rhs.i){}
		
		HasPtr &operator=(const HasPtr &rhs){
			ps = new string(*(rhs.ps));
			i = rhs.i;
		}
		~HasPtr(){
			if(ps)
				delete ps;
			cout << "Destructor called!" << endl;
		}
	private:
		string *ps;
		int i;
};

#endif