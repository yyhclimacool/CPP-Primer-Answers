#include <string>
#include <iostream>

using namespace std;

class Screen {
public:
    using pos = string::size_type;

    Screen() = default;
    // 定义在类内的构造函数是隐式内联的
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
    Screen(pos h, pos w, char ch) : height(h), width(w), contents(h * w, ch) {}

    // 定义在类内部的成员函数是隐式内联的
    char get() const { return contents[cursor]; }
    // 显式指定内联
    inline char get(pos ht, pos wd) const;
    // 能在之后被设为内联
    Screen move(pos r, pos c);

    Screen set(char ch) {
        contents[cursor] = ch;
        return *this;
    }
    Screen set(pos r, pos c, char ch) {
        contents[r * width + c] = ch;
        return *this;
    }

    Screen display(ostream &);
    const Screen display(ostream &) const;

private:
    void do_display(ostream &os) const { os << contents; }
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
inline Screen Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

Screen Screen::display(ostream &os) {
    do_display(os);
    return *this;
}

const Screen Screen::display(ostream &os) const {
    do_display(os);
    return *this;
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << std::endl;
}
