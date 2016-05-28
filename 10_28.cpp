#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<typename T>
void print_container(const T &t){
	for(const auto & e : t)
		cout << e << " ";
	cout << endl;
}

int main(){
	vector<int> svec = {1,2,3,4,5,6,7,8,9};
	vector<int> vec1, vec2;
	list<int> vec3;

	copy(svec.cbegin(), svec.cend(), back_inserter(vec1));
	print_container<vector<int>>(vec1);

	copy(svec.cbegin(), svec.cend(), inserter(vec2, vec2.begin()));
	print_container<vector<int>>(vec2);

	copy(svec.cbegin(), svec.cend(), front_inserter(vec3));
	print_container<list<int>>(vec3);

	return 0;
}
