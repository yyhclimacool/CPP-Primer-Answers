
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
		
		Screen &move(pos w, pos h);
		Screen &set(char ch);
		Screen &set(pos w, pos h, char ch);
		Screen &display(ostream &os);
		const Screen &display(ostream &os) const;
	private:
		void do_display(ostream &os) const { os << contents;}
		pos cursor = 0;
		pos width = 0, height = 0;
		string contents;	
};

inline Screen &Screen::move(pos w, pos h){
	cursor = w * width + h;
	return *this;
}
inline Screen &Screen::set(char ch){
	contents[cursor] = ch;
	return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch){
	contents[r * width + c] = ch;
	return *this;
}

Screen &Screen::display(ostream &os){
	do_display(os);
	return *this;
}

const Screen &Screen::display(ostream &os) const {
	do_display(os);
	return *this;
}
#endif // _SCREEN_HPP_