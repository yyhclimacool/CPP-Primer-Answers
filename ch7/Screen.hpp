
#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <iostream>
#include <string>

using namespace std;

class Screen{
	public:
		using pos = string::size_type;
			
		Screen() = default;
		Screen(pos w, pos h):width(w), height(h), contents(w*h, ' '){}
		Screen(pos w, pos h, char ch):width(w), height(h), contents(w*h, ch){}
		
	private:
		pos cursor = 0;
		pos width = 0, height = 0;
		string contents;	
};

#endif // _SCREEN_HPP_