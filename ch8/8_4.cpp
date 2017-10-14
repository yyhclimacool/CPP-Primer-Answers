#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void put_in_vec(ifstream &ifs, vector<string> &vec){
	string str;
	while(getline(ifs, str))
		vec.push_back(str);
}

int main(int argc, char **argv){
	if(argc != 2){
		cerr << "Give me a file to read please." << endl;
		return -1;
	}
	vector<string> svec;
	ifstream ifs(argv[1]);
	put_in_vec(ifs, svec);
	for(const auto &elem : svec)
		cout << elem << endl;
	return 0;
}