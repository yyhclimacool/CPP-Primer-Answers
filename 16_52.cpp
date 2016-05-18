#include <string>
#include <iostream>

using namespace std;

template<typename T, typename ... Args>
void foo(const T &, const Args & ... rest){
	cout << "sizeof...(Args) : " << sizeof...(Args) << endl;
	cout << "sizeof...(rest) : " << sizeof...(rest) << endl;
}
int main(){
	int i = 0; double d = 3.14; string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
}