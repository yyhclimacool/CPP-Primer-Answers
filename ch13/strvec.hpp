#ifndef _STRVEC_HPP_
#define _STRVEC_HPP_

#include <memory>
#include <iostream>

using namespace std;

class StrVec{
	public:
		StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
		StrVec(const StrVec &);
		StrVec &operator=(const StrVec &);
		~StrVec();
		void push_back(const string &);
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements;};
		string *begin() const { return elements;}
		string *end() const { return first_free;}
		
	private:
		static allocator<string> alloc;
		void check_n_alloc(){
			if(frist_free == cap) reallocate();
		}
		pair<string *, string *> alloc_n_copy
			(const string *, const string *);
		void free();
		void reallocate();
		string *elements;
		string *first_free;
		string *cap;
};

void StrVec::push_back(const string &rhs){
	check_n_alloc();
	alloc.construct(first_free++, rhs);
}

pair<string *, string *> StrVec::alloc_n_copy
	(const string *lhs, const string *rhs){
	auto data = alloc.allocate(rhs - lhs);
	return {data, uninitialized_copy(lhs, rhs, data)};
}

void StrVec::free(){
	if(element){
		for(auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap-elements);
	}
}

StrVec::StrVec(const StrVec &sv){
	auto newdata = alloc_n_copy(sv.begin(), sv.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }
	
StrVec &StrVec::operator=(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i < size(); ++i){
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + capacity;
}
#endif