#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class StrBlob{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> &il);
	size_type size() const {return data->size();}
	bool empty() const { return data->empty();}
	void push_back(const string &s){data->push_back(s);}
	void pop_back();

	string &front();
	const string &front() const;
	string &back();
	const string &back() const;
private:
	shared_ptr<vector<string>> data;
	void check_size(size_type sz, const string &msg) const {
		if(sz >= data->size())
			throw out_of_range(msg);
	}
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}

StrBlob::StrBlob(initializer_list<string> &il):data(make_shared<vector<string>>(il)){}

void StrBlob::pop_back(){
	check_size(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string &StrBlob::front(){
	check_size(0, "front on empty StrBlob");
	return data->front();
}

const string &StrBlob::front() const {
	check_size(0, "front on emtpy StrBlob");
	return data->front();
}

string &StrBlob::back(){
	check_size(0, "back on empty StrBlob");
	return data->back();
}

const string &StrBlob::back() const {
	check_size(0, "back on empty StrBlob");
	return data->back();
}

int main(){

}
