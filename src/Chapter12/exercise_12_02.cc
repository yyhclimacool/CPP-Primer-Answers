#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class StrBlob{
public:
    using size_type = vector<string>::size_type;

    StrBlob() : data_(make_shared<vector<string>>()) {}
    StrBlob(const initializer_list<string> &il) : data_(make_shared<vector<string>>(il)) {}

    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }

    void push_back(const string &);
    void pop_back();
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;
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

const string &StrBlob::front() const {
    check(0, "front on emtpy vector");
    return data_->front();
}

string &StrBlob::back() {
    check(0, "back on emtpy vector");
    return data_->back();
}

const string &StrBlob::back() const {
    check(0, "back on empty vector");
    return data_->back();
}

int main() {
    StrBlob sv{"fine", "by", "me"};
    sv.back() = "ME";
    cout << sv.back() << endl;
}
