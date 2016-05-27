#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
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
*/

bool more_than_5(const string &str){
	if(str.size() >= 5)
		return true;
	else
		return false;
}

int main(){
	vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	auto it = partition(story.begin(), story.end(), more_than_5);
	for(auto itr = story.cbegin(); itr != it; ++itr)
		cout << *itr << " ";
	cout << endl;
	return 0;
}
