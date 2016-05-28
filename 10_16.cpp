#include <iostream>
#include <vector>
#include <algorithm>

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

void biggies(vector<string> words, vector<string>::size_type sz){
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) 
		-> bool {return lhs.size() < rhs.size();});
	auto wc = find_if(words.begin(), words.end(), [sz](const string &rhs) -> bool {return rhs.size() >= sz;});
	auto count = words.end() - wc;
	cout << count << " words of length " << sz << " or longer :" << endl;
	for_each(wc, words.end(), [](const string &rhs) -> void{cout << rhs << " ";});
	cout << endl;
}

int main(){
	vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(story, 5);
	return 0;
}
