#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void reverse_print(const T &t){
	ostream_iterator<typename T::value_type> ost(cout, " ");
	copy(t.crbegin(), t.crend(), ost);
	cout << endl;
}

int main(){
	vector<int> ivec = {1,2,3,4,5,6,7,8,9};
	reverse_print<vector<int>>(ivec);
	return 0;
}
