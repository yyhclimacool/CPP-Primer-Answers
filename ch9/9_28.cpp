#include <forward_list>
#include <iostream>

using namespace std;

void myfunc(forward_list<string> &slst, const string &lhs, const string &rhs){
	auto prev = slst.before_begin();
	auto curr = slst.begin();
	while(curr != slst.end()){
		if(*curr == lhs){
			prev = curr;
			curr = slst.insert_after(curr, rhs);
		}else{
			prev = curr;
			++curr;
		}
	}
	if(curr == slst.end())
		curr = slst.insert_after(prev, rhs);
}

int main(){
	forward_list<string> slst = {"we", "are", "fine", "fine"};
	myfunc(slst, "are", "not");
	for(const auto & e : slst)
		cout << e << "\t";
	cout << endl;
	return 0;
}
