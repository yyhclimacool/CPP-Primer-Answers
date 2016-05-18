#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b){
	return a + b;
}

int minu(int a, int b){
	return a - b;
}

int multi(int a, int b){
	return a*b;
}

int divide(int a, int b){
	return a/b;
}

typedef int (*f)(int, int);

int main(){
	vector<f> fv;
	fv.push_back(add);
	fv.push_back(minu);
	fv.push_back(multi);
	fv.push_back(divide);

	int x = 10, y = 5;

	for(const auto &elem : fv){
		cout << elem(x, y) << endl;
	}
	return 0;
}
