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
	//StrVec sv({"we", "are", "fine"});
	vector<String> sv;
	sv.push_back("we");
	sv.push_back("are");
	sv.push_back("fine");
	return 0;
}