#include "HasPtr.h"

HasPtr& HasPtr::operator=(HasPtr rhs){
	swap(*this, rhs);
	return *this;
}

ostream &print(ostream &os, const HasPtr &rhs){
    os << *rhs.ps << " " << rhs.i << endl;
}

inline void swap(HasPtr &lhs, HasPtr &rhs){
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
#ifndef NDEBUG
	std::cout << "File: " << __FILE__ << " -> function: " << __func__ << " -> line NO: " << __LINE__ << " -> at time: " << __TIME__ << " -> on date: " << __DATE__ << std::endl;
#endif
}

bool HasPtr::operator<(const HasPtr &rhs) const{
	return i < rhs.i;
}
