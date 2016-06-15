#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
public:
	typedef vector<string>::size_type size_type;
	StrBlob():data(make_shared<vector<string>>()){};
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
	size_type size()const {return data->size();}
	bool empty() const {return data->empty();}
	void push_back(const string &s){data->push_back(s);}
	void pop_back();
	string &front();
	const string &front() const;
	string &back();
	const string &back() const;

	StrBlobPtr begin(){return StrBlobPtr(*this);}
	StrBlobPtr end() {return StrBlobPtr(*this, this->size());}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg);
};

void StrBlob::check(size_type i, const string &msg){
	if(i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back(){
	check(0, "pop_back on an empty StrBlob");
	data->pop_back();
}

string &StrBlob::front(){
	check(0, "front on an empty StrBlob");
	return data->front();
}

string &StrBlob::back(){
	check(0, "back on an empty StrBlob");
	return data->back();
}

const string &StrBlob::front() const{
	check(0, "front on an empty StrBlob");
	return data->front();
}

const string &StrBlob::back() const {
	check(0, "back on an empty StrBlob");
	return data->back();
}

///////////////////////////////////////////////////////////////////////////

class StrBlobPtr {
public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &a, size_t sz = 0):wptr(a.data), curr(sz){}
	string &deref() const;
	StrBlobPtr &incr();
private:
	weak_ptr<vector<string>> wptr;
	size_t curr;
	shared_ptr<vector<string>> check(size_t, const string &) const;
};

shared_ptr<vector<string>>
check(size_t i, const string &msg){
	auto ret = wptr.lock();
	if(!ret){
		throw runtime_error("unbound StrBlobPtr");
	}
	if(i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string &StrBlobPtr::deref() const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

int main(){

}
