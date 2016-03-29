#include <iostream>
#include <functional>
#include <map>

using namespace std;

int add(int lhs, int rhs){
	return lhs+rhs;
}

struct devide{
	int operator()(int lhs, int rhs){
		return lhs / rhs;
	}
};

auto mod = [](int lhs, int rhs)->int{return lhs % rhs;};


int main(){
	map<string, function<int(int, int)>> binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"*", [](int lhs, int rhs){return lhs * rhs;}},
		{"/", devide()},
		{"%", mod}
	};

	cout << binops["+"](10, 5) << endl;
	cout << binops["-"](10, 5) << endl;
	cout << binops["*"](10, 5) << endl;
	cout << binops["/"](10, 5) << endl;
	cout << binops["%"](10, 5) << endl;
}
