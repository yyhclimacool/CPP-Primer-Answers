#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

void readFile(vector<string> &svec, ifstream &fs){
	istream_iterator<string> if_it(fs), eof;
	svec.assign(if_it, eof);
}

template<typename T>
void print_container(const T &t){
	ostream_iterator<typename T::value_type> os_it(cout, " ");
	copy(t.cbegin(), t.cend(), os_it);
	cout << endl;
}

int main(int argc, char **argv){
	if(argc != 2){
		cerr << "Give me a file to READ !" << endl;
		return EXIT_FAILURE;
	}
	ifstream ifs(argv[1]);
	vector<string> svec;
	readFile(svec, ifs);
	print_container<vector<string>>(svec);
	return 0;
}
