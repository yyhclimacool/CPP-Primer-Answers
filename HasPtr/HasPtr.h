#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::endl;

class HasPtr{
    friend ostream &print(ostream &, const HasPtr &rhs);
public:
    HasPtr(const string &s = string()):ps(new string(s)), i(0){}
    HasPtr(const HasPtr &rhs):ps(new string(*rhs.ps)), i(rhs.i){}
    HasPtr &operator=(const HasPtr &rhs);
    ~HasPtr(){ delete ps; }
private:
    string *ps;
    int i;
};
