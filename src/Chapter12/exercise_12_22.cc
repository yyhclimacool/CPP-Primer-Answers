#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob():data_(make_shared<vector<string>>()) {}
    StrBlob(const initializer_list<string> &il):data_(make_shared<vector<string>>(il)) {}

    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }

    void push_back(const string &);
    void pop_back();
    string &front();
    string &front() const;
    string &back();
    string &back() const;

    StrBlobPtr begin();
    ConstStrBlobPtr begin() const;
    StrBlobPtr end();
    ConstStrBlobPtr end() const;
private:
    shared_ptr<vector<string>> data_;
    void check(size_type, const string &) const;
};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data_->size())
        throw out_of_range(msg);
}

void StrBlob::push_back(const string &s) {
    data_->push_back(s);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty vector");
    data_->pop_back();
}

string &StrBlob::front() {
    check(0, "front on empty vector");
    return data_->front();
}

string &StrBlob::front() const {
    check(0, "front on emtpy vector");
    return data_->front();
}

string &StrBlob::back() {
    check(0, "back on emtpy vector");
    return data_->back();
}

string &StrBlob::back() const {
    check(0, "back on empty vector");
    return data_->back();
}

class StrBlobPtr {
public:
    StrBlobPtr():curr(0) {}
    StrBlobPtr(StrBlob &a, size_t n = 0) : wptr(a.data_), curr(n) {}
    
    string &deref();
    StrBlobPtr &incr();
private:
    shared_ptr<vector<string>> check(size_t, const string &);
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) {
    auto ret = wptr.lock();
    if (!ret) 
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() {
    auto ret = check(curr, "deref");
    return (*ret)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    auto ret = check(curr, "incr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data_->size() - 1);
}

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr():curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t n = 0) : wptr(a.data_), curr(n) {}
    
    const string &deref();
    ConstStrBlobPtr &incr();
private:
    shared_ptr<vector<string>> check(size_t, const string &);
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) {
    auto ret = wptr.lock();
    if (!ret) 
        throw runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

const string &ConstStrBlobPtr::deref() {
    auto ret = check(curr, "deref");
    return (*ret)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    auto ret = check(curr, "incr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
    return ConstStrBlobPtr(*this, data_->size() - 1);
}

int main() {
    StrBlob sb{"a", "an", "the", "and"};
    cout << sb.begin().deref() << endl;
    cout << sb.end().deref() << endl;
    const StrBlob csb(sb);
    cout << csb.end().deref() << endl;
}
