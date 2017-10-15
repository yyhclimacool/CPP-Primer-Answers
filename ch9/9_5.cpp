#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

using it = vector<int>::iterator;

it myFind(it beg, it end, int ival){
	while(beg != end){
		if(ival == *beg){
			return beg;
		}
		++beg;
	}
		return end;
}

int main(){
	vector<int> ivec = {1,2,3,4,5,6,7,87};
	it itr = (myFind(ivec.begin(), ivec.end(), 0));
	if(itr != ivec.end())
		cout << *itr << endl;
	else
		cout << "Not found!" << endl;
	return 0;
}
