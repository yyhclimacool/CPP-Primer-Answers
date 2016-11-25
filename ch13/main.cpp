#include "HasPtr.hpp"
#include "numbered.hpp"
#include "HasPtrV1.hpp"
#include "strvec.hpp"
#include "String.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	cout << "******************Test for StrVec******************" << endl;
	StrVec strv({"we", "are", "fine"});
	cout << "******************Test for String******************" << endl;
	vector<String> sv;
	sv.push_back("we");
	sv.push_back("are");
	sv.push_back("fine");
	cout << "******************Test for HasPtr******************" << endl;
	
	return 0;
}