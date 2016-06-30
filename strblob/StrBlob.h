#ifndef _STRBLOB_H_
#define _STRBLOB_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "StrBlobPtr.h"

using namespace std;

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

#endif // _STRBLOB_H_
