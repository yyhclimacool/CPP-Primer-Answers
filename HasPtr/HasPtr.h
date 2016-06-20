#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::endl;

class HasPtr{
    friend ostream &print(ostream &, const HasPtr &rhs);
	friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string(), int val = 0):ps(new string(s)), i(val){}
    HasPtr(const HasPtr &rhs):ps(new string(*rhs.ps)), i(rhs.i){}
    HasPtr &operator=(HasPtr rhs);
	bool operator<(const HasPtr &) const;
    ~HasPtr(){ delete ps; }
private:
    string *ps;
    int i;
};
