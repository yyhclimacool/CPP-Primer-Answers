#include <forward_list>
#include <iostream>

using namespace std;

void myfunc(forward_list<int> &lst){
	auto prev = lst.before_begin();
	auto curr = lst.begin();
	while(curr != lst.end()){
		if(*curr % 2)
			curr = lst.erase_after(prev);
		else{
			prev = curr;
			++curr;
		}
	}
}

int main(){
	forward_list<int> ilst = {1,2,3,4,5,6,7,8,9};
	for(const auto & e : ilst)
		cout << e << "\t";
	cout << endl;
	myfunc(ilst);
	for(const auto & e: ilst)
		cout << e << "\t";
	cout << endl;
	return 0;
}
