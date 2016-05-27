#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void elimDups(vector<string> &svec){
	cout << "In elimDups: the original vector: " << endl;
	for(const auto & e : svec)
		cout << e << '\t';
	cout << endl;
	sort(svec.begin(), svec.end());
	cout << "In elimDups: the sorted vector: " << endl;
	for(const auto & e : svec)
		cout << e << '\t';
	cout << endl;
	auto end_unique = unique(svec.begin(), svec.end());
	cout << "In elimDups: after unique called: " << endl;
	for(const auto & e : svec)
		cout << e << '\t';
	cout << endl;
	svec.erase(end_unique, svec.end());
	cout << "In elimDups: the final state of vector: " << endl;
	for(const auto & e : svec)
		cout << e << '\t';
	cout << endl;
}

int main(){
	vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(story);
	return 0;
}
