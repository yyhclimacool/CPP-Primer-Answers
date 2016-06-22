#include "StrVec.h"
#include <utility>

using std::allocator;

void StrVec::push_back(const string &s){
    chk_n_alloc();    // now we know that we got enough space to put new string
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *lhs, const string *rhs){
    auto data = alloc.allocate(rhs - lhs);
    return {data, uninitialized_copy(lhs, rhs, data)};
}

void StrVec::free(){
    if(elements){    // if elements equals to 0, we do nothing
        for(auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    cap = first_free = newdata.second;
}

StrVec::~StrVec(){ free(); }

StrVec &StrVec::operator=(const StrVec &s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    free();
    elements = newdata.first;
    cap = first_free = newdata.second;
    return *this;
}

void StrVec::reallocate(){
     auto newcapacity = size() ? 2 * size() : 1;
     auto newdata = alloc.allocate(newcapacity);

     auto dest = newdata;
     auto elem = elements;

     for(size_t i = 0; i != size(); ++i)
         alloc.construct(dest++, std::move(*elem++));
     free();
     elements = newdata;
     first_free = dest;
     cap = elements + newcapacity;
}

void StrVec::reserve(size_t sz){
    if(sz > capacity()){

    }
}

void StrVec::resize(sizet_t sz){

}
