#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stringstream>

void word_transform(ifstream &map_file, ifstream &inputs){
	auto rules = build_map(map_file);
	string line;
	while(getline(inputs, line)){
		istringstream strm(line);
		bool first_word = true;
		string word;
		while(strm >> word){
			if(first_word)
				first_word = false;
			else{
				cout << " ";
				cout << transform(word, rules);
			}

		}
		cout << endl;
	}
}

map<string, string> build_map(ifstream &map_file){
	map<string, string> rules;
	string word, line;
	while(map_file >> word && getline(map_file, line)){
		if(line.size() > 0)
			rules[word] = line.substr(1);
		else
			throw runtime_error("no rule for " + word);
	}
	return rules;
}

const string &transform(const string &str, const map<string, string> &rules){
	auto iter = rules.find(str);
	if(iter != rules.cend())
		return iter->second;
	else
		return str;
}

int main(int argc, char **argv){
	if(argc != 3){
		cerr << "Usage: a.out <map_file> <input_file>" << endl;
		exit(0);
	}
	ifstream map_file(argv[1]);
	ifstream inputs(argv[2]);
	word_transform(map_file, inputs);
	return 0;
}