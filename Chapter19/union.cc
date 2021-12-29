#include <string.h>

#include <iostream>
#include <map>
#include <vector>

union Token {
  int8_t   cval;
  uint8_t  ucval;
  int      ival;
  uint64_t uval;
  double   dval;
  // std::vector<int> ivec;
};

void anonymous_union() {
  union {
    char   cval;
    int    ival;
    double dval;
  }; // 匿名union，自动定义一个未命名的对象，可以直接访问它的成员

  std::cout << "cval=" << cval << ", ival=" << ival << ", dval=" << dval << std::endl;

  cval = 216;
  ival = 42;
  dval = 3.14;

  std::cout << "cval=" << cval << ", ival=" << ival << ", dval=" << dval << std::endl;
}

int main() {
  std::cout << "sizeof(std::string) = " << sizeof(std::string) << std::endl;
  std::cout << "sizeof(std::vector<int>) = " << sizeof(std::vector<int>) << std::endl;
  std::cout << "sizeof(std::vector<float>) = " << sizeof(std::vector<float>) << std::endl;
  std::cout << "sizeof(std::vector<double>) = " << sizeof(std::vector<double>) << std::endl;
  std::cout << "sizeof(std::map) = " << sizeof(std::map<int, int>) << std::endl;
  std::cout << "sizeof(Token) = " << sizeof(Token) << std::endl;

  Token tk;
  tk.cval = -1;
  std::cout << "tk.cval=" << static_cast<int8_t>(tk.cval) << std::endl;
  std::cout << "tk.ucval=" << static_cast<uint8_t>(tk.ucval) << std::endl;

  int cval = 10;
  anonymous_union();
}