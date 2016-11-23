#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

template<typename T>
void print_container(const T &t){
	ostream_iterator<typename T::value_type> os_it(cout, " ");
	copy(t.cbegin(), t.cend(), os_it);
	cout << endl;
}

int main(){
	vector<int> ivec = {1,2,3,4,5,6,7,8,9,0};
	list<int> ilst(ivec.crbegin() + 2, ivec.crbegin() + 7);
	print_container<list<int>>(ilst);
	return 0;
}
