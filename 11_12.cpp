#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void vec_of_pair(vector<pair<string, int>> &pv, istream &is){
	string word;
	int ival;
	while(is >> word >> ival){
		pv.push_back(make_pair(word, ival));
	}
}

int main(){
	vector<pair<string, int>> myVec;
	vec_of_pair(myVec, cin);
	for(const auto & e : myVec){
		cout << e.first << " " << e.second << endl;
	}
	return 0;
}
