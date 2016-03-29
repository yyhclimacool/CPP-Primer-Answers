#include <iostream>
#include <vector>

using namespace std;

class InputString{
public:
	InputString(istream &in = cin):is(in){}
	string operator()(string &str) const {
		is >> str;
		if(is)	return str;
		else return string();
	}
private:
	istream &is;
};

int main(){
	InputString ins;
	vector<string> svec;
	string word;
	for(int i = 0; i < 10; i++){
		svec.push_back(ins(word));
	}
	cout << endl;
	for(const auto &elem : svec)
		cout << elem << " ";
	cout << endl;
}
