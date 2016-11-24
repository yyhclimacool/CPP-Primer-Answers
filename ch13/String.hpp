#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <memory>
#include <string.h>
#include <algorithm>

class String{
	public:
		String():elements(nullptr), first_free(nullptr), cap(nullptr){}
		String(const char *ch);
		~String() { free(); }
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
	std::copy(ch, ch+sz, newdata);
	elements = newdata;
	first_free = cap = elements + sz;
}

#endif