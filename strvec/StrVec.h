#ifndef _STRVEC_H_
#define _STRVEC_H_

#include <iostream>
#include <string>
#include <memory>
#include <utility>

using std::allocator;
using std::string;
using std::pair;

class StrVec{
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    void reserve(size_t sz);
    void resize(size_t sz);
    size_t capacity() const { return cap - elements; }
    string *begin() const {return elements;}
    string *end() const { return first_free; }
private:
    static allocator<string> alloc;
    string *elements;
    string *first_free;
    string *cap;

    void chk_n_alloc(){
        if(size() == capacity())
            reallocate();
    }

    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void free();
    void reallocate();
};

#endif
