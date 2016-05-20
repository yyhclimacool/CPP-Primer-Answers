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

    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);
    Screen &display(ostream &os);
    const Screen &display(ostream &os) const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(ostream &os) const { os << contents;}
};

inline char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

inline Screen &Screen::move(pos r, pos c){
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c){
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch){
    contents[r * width + c] = ch;
    return *this;
}

inline Screen &Screen::display(ostream &os){
    do_display(os);
    return *this;
}

inline const Screen &Screen::display(ostream &os) const {
    do_display(os);
    return *this;
}

#endif // _SCREEN_H_
