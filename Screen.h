#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#include <string>

class Screen{
public:
    typedef std::string::size_type pos;
    
    Screen() = default;
    Screen(pos ht, pos wd):height(ht), width(wd),contents(ht * wd, ""){}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){}
    
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    
    Screen &move(pos ht, pos wd);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline char get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen &move(pos r, pos c){
    cursor = r * width + c;
    return *this;
}

#endif // _SCREEN_H_
