#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int> &ivec, int ori){
	for_each(ivec.begin(), ivec.end(), [ori](int &ival) -> void {ival += ori;});
	for_each(ivec.begin(), ivec.end(), [](int ival) -> void {cout << ival << " ";});
	cout << endl;
}

int main(){
	vector<int> ivec = {1,2,3,4,5,6,7,8,9};
	func(ivec, 10);
	return 0;
}
