#include "HasPtr.hpp"
#include "numbered.hpp"
#include "HasPtrV1.hpp"
#include <iostream>

using namespace std;

int main(){
	//numbered a, b = a, c = b;
	//f(a), f(b), f(c);
	HasPtrV1 hp1;
	HasPtrV1 hp2(hp1);
	HasPtrV1 hp3(hp1);
	hp3 = hp2;
	return 0;
}