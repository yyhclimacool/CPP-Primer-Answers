#include "HasPtr.hpp"
#include "numbered.hpp"
#include <iostream>

using namespace std;

int main(){
	numbered a, b = a, c = b;
	f(a), f(b), f(c);
}