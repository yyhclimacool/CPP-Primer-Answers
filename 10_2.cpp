#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main(){
	list<string> slst;
	string sval;
	cout << "Enter some value into vector: " << endl;
	while(cin >> sval)
		slst.push_back(sval);
	cout << "\nOK, now enter the value you want to lookup: " << endl;
	cin.clear();
	cin >> sval;
	auto cnt = count(slst.cbegin(), slst.cend(), sval);
	cout << "The Number you entered occured " << cnt << " times." << endl;
	return 0;
}
