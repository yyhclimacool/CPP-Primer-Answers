#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
  typedef string::size_type pos;
  using MoveAction = Screen &(Screen::*)();

  Screen() : contents(), cursor(0), height(80), width(24) {}
  Screen(const string &s, int c, int h, int w) : contents(s), cursor(c), height(h), width(w) {}
  static const string Screen::*data() {
    return &Screen::contents;
  }

  const char get_cursor() const { return contents[cursor]; }
  char get(pos p) { return contents[p]; }
  char get(pos a, pos b) const { return 'a'; }

  enum Direction {HOME, UP, DOWN, LEFT, RIGHT};

  Screen &home() { cout << "move home" << endl; return *this; }
  Screen &up() { cout << "move up" << endl; return *this; }
  Screen &down() { cout << "move down" << endl; return *this; }
  Screen &left() { cout << "move left" << endl; return *this; }
  Screen &right() { cout << "move right" << endl; return *this; }

  Screen &move(Direction d) { return (this->*menu[d])(); }
private:
  string contents;
  pos cursor;
  pos height, width;

  static MoveAction menu[];
};

Screen::MoveAction Screen::menu[] {
  &Screen::home,
  &Screen::up,
  &Screen::down,
  &Screen::left,
  &Screen::right
};

using Action = char (Screen::*)(Screen::pos, Screen::pos) const;

Screen &action(Screen &s, Action act = &Screen::get) {
  cout << (s.*act)(12, 12) << endl;
  return s;
}

int main() {
  // pointer to member
  const string Screen::*pdata = Screen::data();
  Screen sc("fine", 1, 80, 24);
  cout << sc.*pdata << endl;

  auto pmf = &Screen::get_cursor;
  cout << (sc.*pmf)() << endl;

  char (Screen::*pmf1)(Screen::pos, Screen::pos) const;
  pmf1 = &Screen::get;

  cout << (sc.*pmf1)(1,2) << endl;

  Action get = &Screen::get;
  cout << (sc.*get)(12, 12) << endl;

  action(sc);
  action(sc, &Screen::get);

  sc.move(Screen::HOME);
  sc.move(Screen::LEFT);
}
