#include <iostream>

using namespace std;

void func(){
	int val = 21;
	auto f = [&val]() -> bool { 
		if(val == 0)
			return true;
		else{
			while(val != 0)
				--val;
			return false;
		}
	};
	bool res = f();
	cout << res << endl;
	val = 0;
	res = f();
	cout << res << endl;
}

int main(){
	func();
	return 0;
}
