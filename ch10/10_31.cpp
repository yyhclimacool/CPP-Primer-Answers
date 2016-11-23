#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	istream_iterator<int> ite(cin), eof;
	vector<int> ivec(ite, eof);
	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> os_it(cout, " ");
	unique_copy(ivec.cbegin(), ivec.cend(), os_it);
	cout << endl;
	return 0;
}
