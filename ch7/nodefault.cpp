#include <vector>
#include <iostream>

using namespace std;

#ifndef _NODEFAULT_HPP_
#define _NODEFAULT_HPP_

class NoDefault{
	public:
		NoDefault(int i):ival(i){}
	private:
		int ival;
};

class C{
	public:
		C(): nd(0){}
	private:
		NoDefault nd;
};

#endif // _NODEFAULT_HPP_


int main(){
	//vector<NoDefault> vec(10);
	vector<C> cvec(10);
	return 0;
}