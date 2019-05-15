#include <iostream>
#include <string>

using namespace std;

// func返回包含10个string元素的数组的引用
string (&func())[10];

using arrS = string[10];

// 使用类型别名
arrS &func();

// 使用尾置返回类型
auto func() -> string(&)[10];

string sa[10];

// 使用decltype
decltype(sa) &func();
