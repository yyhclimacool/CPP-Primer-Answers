#include "HasPtr.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<HasPtr> hpv;
	hpv.push_back(HasPtr("we", 2));	
	hpv.push_back(HasPtr("are", 1));
	hpv.push_back(HasPtr("fine", 4));
	hpv.push_back(HasPtr("dollar", 3));
	sort(hpv.begin(), hpv.end());
    return 0;
}
