#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define sz 10

int main(){
	vector<int> ivec(sz);
	for(const auto & e : ivec)
		cout << e << '\t';
	cout << endl;
	fill_n(ivec.begin(), sz, 0);
	for(const auto & e : ivec)
		cout << e << '\t';
	cout << endl;
	return 0;
}
