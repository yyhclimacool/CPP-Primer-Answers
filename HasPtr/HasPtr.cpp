#include "HasPtr.h"

HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

ostream &print(ostream &os, const HasPtr &rhs){
    os << *rhs.ps << " " << rhs.i << endl;
}
