#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

void count_words(map<string, size_t> &wc, const set<string> &exclude){
	string word;
	while(cin >> word){
		if(exclude.find(word) == exclude.end())
			auto res = wc.insert({word, 1})		// insert返回一个pair<map<string, size_t>::iterator, bool>
			if(!res.seconde)						// 如果插入成功
				++res.first->second;
	}
}

int main(){
	map<string, size_t> word_c;
	set<string> exclude = {"a", "A", "An", "an", "the", "The", "and", "And", "or", "Or"};
	count_words(word_c, exclude);
	for(auto it = word_c.cbegin(); it != word_c.cend(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
