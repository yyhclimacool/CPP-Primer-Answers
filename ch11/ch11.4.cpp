#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

string &make_it_lower(string &str){
	for(auto &elem : str)
		elem = tolower(elem);
	return str;
}

string &no_punc(string &str){
	size_t length = str.size();
	if(ispunct(str[length-1]))
		str.erase(length-1);
	if(ispunct(str[0]))
		str.erase(0,1);
	return str;
}

int main(int argc, char **argv){
	if(argc != 2)
		cerr << "Usage: a.out <filename>" << endl;
	ifstream ifs(argv[1]);
	string word;
	map<string, size_t> word_count;
	set<string> exclude = {"A", "An", "And", "Or", "But", "The",
				"a", "an", "and", "or", "but", "the"};	
	while(ifs >> word){
		if(exclude.find(no_punc(make_it_lower(word))) == exclude.end())
			++word_count[word];
	}
	for(const auto &elem : word_count){
		cout << elem.first << " occurs " << elem.second << "time(s)" << endl;
	}
	ifs.close();
	return 0;
}
