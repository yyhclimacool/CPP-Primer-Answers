#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

map<string, string> buildMap(ifstream &map_file){
	map<string, string> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file, value)){
		if(value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + value);
	}
	return trans_map;
}

string transform(const string &word, const map<string, string> &trans_map){
	auto map_it = trans_map.find(word);
	if(map_it != trans_map.end())
		return map_it->second;
	else
		return word;
}

void word_transform(ifstream &map_file, ifstream &input){
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input, text)){
		istringstream iss(text);
		string word;
		bool firstword = true;
		while(iss >> word){
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char **argv){
	if(argc != 3){
		cerr << "I need a map file and an input file" << endl;
		return EXIT_FAILURE;
	}
	ifstream mapfile(argv[1]);
	ifstream inputfile(argv[2]);
	word_transform(mapfile, inputfile);
	return 0;
}
