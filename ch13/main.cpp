#include "HasPtr.hpp"
#include "numbered.hpp"
#include "HasPtrV1.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<HasPtr> hv = {{"never mind", 8}, {"do it or not", 4}, {"we are fine", 2},{"what do you want", 90}};
	sort(hv.begin(), hv.end());
	for(const auto ele : hv)
		cout << ele << endl;
	return 0;
}