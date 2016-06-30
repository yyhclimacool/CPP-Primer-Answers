#include "StrBlobPtr.h"
#include <memory>

using namespace std;

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
