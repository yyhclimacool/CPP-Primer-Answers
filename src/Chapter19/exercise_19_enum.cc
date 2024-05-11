#include <iostream>
#include <string>

using namespace std;

enum class open_modes {input, output, append};
enum color {red, yellow, green};
//enum stoplight {red, yellow, green}; // redeclaration of red, yellow, green

int main() {
  enum stoplight {red, yellow, green}; // OK
  color hair = color::red;
  stoplight cross_road = red;
  open_modes readfile = open_modes::input;

  enum intTypes : unsigned long long {
    charType = 8, shortType = 16, intType = 32, longType = 32, longlongType = 64};

  // 限定作用域的枚举类型不会隐式转换
  int ival = intTypes::shortType;
  cout << "intTypes::shortType implicitly convert to int is " << ival << endl;
}
