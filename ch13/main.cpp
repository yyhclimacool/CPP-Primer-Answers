#include "HasPtr.hpp"
#include <iostream>

using namespace std;

int main(){
	HasPtr pt("Are you OK?");
	HasPtr pt1(pt);
	HasPtr pt2;
	pt2 = pt;
}