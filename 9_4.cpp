#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

bool myFind(vector<int>::iterator beg, vector<int>::iterator end, int ival){
	bool result = false;
	while(beg != end){
		if(ival == *beg){
			result = true;
			break;
		}
		++beg;
	}
	return result;
}

int main(){
	vector<int> ivec = {1,2,3,4,5,6,7,87};
	cout << myFind(ivec.begin(), ivec.end(), 7) << endl;
	return 0;
}
