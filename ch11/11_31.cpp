#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <string>

using namespace std;

int main(){
	multimap<string, string> authors{
		{"kevin", "CPP Primer 5th ed."},
		{"kevin", "Don't look at yourself"},
		{"Alan de Botton", "Confort from philosiphy"},
		{"Erlend Loe", "我是个年轻人,我心情不太好"},
		{"Erlend Loe", "我已经结婚了，我心情还不好"}
	};

	for(const auto & e : authors){
		cout << e.first << " " << e.second << endl;
	}
	string author = "lua";
	auto beg = authors.lower_bound(author), end = authors.upper_bound(author);
	if(beg != end)
		authors.erase(beg, end);
	else
		cout << "erased nothing" << endl;
	for(const auto & e : authors){
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
