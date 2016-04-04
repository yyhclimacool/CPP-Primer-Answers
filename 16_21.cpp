#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <memory>

using namespace std;

class DebugDelete {
public:
	DebugDelete(ostream &_os = std::cerr) :os(_os) {}
	template<typename T> void operator()(T *p) const { cout << "deleting unique_ptr ------ " << *p << endl; delete p; }
private:
	ostream &os;
};

int main()
{
	unique_ptr<int, DebugDelete> ptr(new int(42), DebugDelete());
	unique_ptr<string, DebugDelete> sptr(new string("I said fine"), DebugDelete());
}
