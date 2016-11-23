#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<int> ivec = {2,3,4,5,6,7,8,9,1};
	auto sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << "The sum of vector is: " << sum << endl;
	return 0;
}
