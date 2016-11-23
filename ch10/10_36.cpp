#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
void print_container(const T &t){
	ostream_iterator<typename T::value_type> os_it(cout, " ");
	copy(t.cbegin(), t.cend(), os_it);
	cout << endl;
}

int main(){
	list<int> ilst = {1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1};
	auto it = find(ilst.crbegin(), ilst.crend(), 0);
	list<int> ilst1(it.base(), ilst.cend());
	print_container<list<int>>(ilst1);
	return 0;
}
