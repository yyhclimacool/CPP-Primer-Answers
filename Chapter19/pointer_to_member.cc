#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
  typedef string::size_type pos;
  Screen() : contents(), cursor(0), height(80), width(24) {}
  Screen(const string &s, int c, int h, int w) : contents(s), cursor(c), height(h), width(w) {}
  static const string Screen::*data() {
    return &Screen::contents;
  }
private:
  string contents;
  pos cursor;
  pos height, width;
};

int main() {
  // pointer to member
  const string Screen::*pdata = Screen::data();
  Screen sc("fine", 1, 80, 24);
  cout << sc.*pdata << endl;
}
