#include "StrVec.h"
// 下面这一行代码如果没有会导致ld链接错误
// 因为在头文件中的alloc只是声明而没有定义
// 但是静态成员只能在程序的声明周期内定义一次
// 所以定义不能放在头文件中
// 在类的外部定义静态成员和定义普通类的成员一样
// 首先指定成员的数据类型，然后指定成员的作用域为类的作用域
allocator<string> StrVec::alloc;

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
        for_each(elements, first_free, [](string s_str)->void { alloc.destroy(&s_str);});
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
        auto newdata = alloc.allocate(sz);
        auto dest = newdata;
        auto elem = elements;
        for(size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + sz;
    }
}

void StrVec::resize(size_t sz){
    if(sz > size() && sz < capacity()){
        first_free = uninitialized_fill_n(first_free, sz-size(), string());
    }
}

StrVec::StrVec(initializer_list<string> &il){
     auto newdata = alloc_n_copy(il.begin(), il.end());
     elements = newdata.first;
     cap = first_free = newdata.second;
}

bool operator==(const StrVec &lhs, const StrVec &rhs){
	if(lhs.size() == rhs.size()){
		bool result = true;
		for(size_t i = 0; i != lhs.size(); ++i){
			if(*(lhs.elements + i) != *(rhs.elements + i))
				result = false;
		}
		return result;
	}
	else
		return false;	
}

bool operator!=(const StrVec &lhs, const StrVec &rhs){
	return !(lhs == rhs);
}









