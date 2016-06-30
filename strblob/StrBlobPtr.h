#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "StrBlob.h"

using namespace std;

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

#endif // _STRBLOBPTR_H_
