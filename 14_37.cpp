#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class EqualOrNot{
public:
	EqualOrNot(int ival = 0):origin(ival){}
	bool operator()(int rhs){
		return origin == rhs;
	}
	int get()const {return origin;}
private:
	int origin;
};

int main(){
	vector<int> ivec;
	for(int i = 0; i < 20; i++)
		ivec.push_back(i+1);
	cout << "before:" << endl;
	for(const auto &elem:ivec)
		cout << elem << " ";
	cout << endl;
	EqualOrNot eq(10);
	replace_if(ivec.begin(), ivec.end(), eq, eq.get());
	cout << "after: " << endl;
	for(const auto &elem:ivec)
		cout << elem << " ";
	cout << endl;
	return 0;
}
