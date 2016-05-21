#ifndef _WINDOW_MGR_H_
#define _WINDOW_MGR_H_

#include <vector>
#include <iostream>

#include "Screen.h"

class Window_mgr{
public:
	using ScreenIndex = std::vector<Screen>::size_type;

	void clear(ScreenIndex id);
private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};

};

void Window_mgr::clear(ScreenIndex id){
	Screen &s = screens[id];
	s.contents = string(width * height, ' ')
}

#endif // _WINDOW_MGR_H_