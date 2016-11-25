#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <memory>
#include <string.h>
#include <algorithm>

class String{
	public:
		String():elements(nullptr), first_free(nullptr), cap(nullptr){}
		String(const char *ch);
		String(const String &rhs);
		String(String &&) noexcept;
		String &operator=(const String &rhs);
		String &operator=(String &&) noexcept;
		~String() { free(); }
		
		size_t size() const { return first_free - elements;}
		size_t capacity() const { return cap - elements; }
		
		char *begin() { return elements;}
		const char *begin() const { return elements;}
		char *end() { return first_free;}
		const char *end() const { return first_free;}
	private:
		void free();
	private:
		static std::allocator<char> alloc;
		char *elements;
		char *first_free, *cap;
	
};

allocator<char> String::alloc;
	
void String::free(){
	if(elements){
		while(first_free != elements){
			alloc.destroy(--first_free);
		}
		alloc.deallocate(elements, cap-elements);
	}
}
	
String::String(const char *ch){
	auto sz = strlen(ch);
	auto newdata = alloc.allocate(sz);
	auto p = newdata;
	//std::copy(ch, ch+sz, newdata);
	std::for_each(ch, ch+sz, [&](char c){alloc.construct(p++, c);});
	elements = newdata;
	first_free = cap = elements + sz;
}

String::String(const String &rhs){
	auto sz = rhs.size();
	auto newdata = alloc.allocate(sz);
	auto p = newdata;
	std::for_each(rhs.begin(), rhs.begin()+sz, [&](char c){alloc.construct(p++, c);});
	elements = newdata;
	first_free = cap = elements + sz;
	cout << "Copy constructor called!" << endl;
}

String::String(String &&rhs) noexcept {
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		
		rhs.elements = rhs.first_free = rhs.cap;
}

String &String::operator=(const String &rhs){
	// 先完成自赋值的情况
	auto sz = rhs.size();
	auto newdata = alloc.allocate(sz);
	auto p = newdata;
	for(size_t i = 0; i < sz; ++i)
		alloc.construct(p++, *(rhs.begin() + i));
	elements = newdata;
	first_free = cap = elements + sz;
	cout << "Copy-Assignment operator called!" << endl;
	return *this;
}

String &String::operator=(String &&rhs) noexcept {
	if(this != &rhs){
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		
		rhs.elements = rhs.first_free = rhs.cap;
	}
	return *this;
}

#endif