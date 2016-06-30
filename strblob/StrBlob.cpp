#include "StrBlob.h"
#include <memory>

using namespace std;

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
