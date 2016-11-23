#include <iostream>
#include <vector>
#include <memory>

using namespace std;

vector<int> *return_vec(){
	return new vector<int>;
}

void build_vec(vector<int> *vp){
	cout << "Enter some int values: " << endl;
	int ival;
	while(cin >> ival)
		vp->push_back(ival);
}

void print_vec(vector<int> *vp){
	for(const auto & e : *vp)
		cout << e << " ";
	cout << endl;
}

int main(){
	auto vp = return_vec();
	build_vec(vp);
	print_vec(vp);
	delete vp;
	return 0;
}
