#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> return_vec(){
	return make_shared<vector<int>>();
}

void build_vec(shared_ptr<vector<int>> vp){
	cout << "Enter some int values: " << endl;
	int ival;
	while(cin >> ival)
		vp->push_back(ival);
}

void print_vec(shared_ptr<vector<int>> vp){
	for(const auto & e : *vp)
		cout << e << " ";
	cout << endl;
}

int main(){
	auto vp = return_vec();
	build_vec(vp);
	print_vec(vp);
	return 0;
}
