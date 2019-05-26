#include <string>

using nsmespace std;

class Screen {
public:
    using pos = string::size_type;

    // 定义在类内部的成员函数是隐式内联的
    char get() const { return contents[cursor]; }
    // 显式指定内联
    inline char get(pos ht, pos wd) const;
    // 能在之后被设为内联
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
};

// 这里inline可以不添加
inline char Screen::get(pos ht, pos wd) const {
    pos csr = ht * width + wd;
    return contents[csr];
}

// 在函数定义处指定内联
inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}
