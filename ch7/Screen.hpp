
#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
	public:
		using ScreenIndex = vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
		vector<Screen> screens;
};

class Screen{
	
	friend void Window_mgr::clear(ScreenIndex);
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

void Window_mgr::clear(ScreenIndex ix){
	Screen &s = screens[ix];
	s.contents = string(s.height * s.width, ' ');
}

#endif // _SCREEN_HPP_