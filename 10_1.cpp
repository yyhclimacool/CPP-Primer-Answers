#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	vector<int> ivec;
	int ival;
	cout << "Enter some value into vector: " << endl;
	while(cin >> ival)
		ivec.push_back(ival);
	cout << "\nOK, now enter the value you want to lookup: " << endl;
	cin.clear();
	cin >> ival;
	auto cnt = count(ivec.cbegin(), ivec.cend(), ival);
	cout << "The Number you entered occured " << cnt << " times." << endl;
	return 0;
}
