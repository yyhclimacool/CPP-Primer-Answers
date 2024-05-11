#include <iostream>
#include <utility> // std::forward<T>(t)

using namespace std;

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
  f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
  f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f1(int a, double b) {
  cout << "a = " << a << ",b = " << b << endl;
}
void f2(int a, double &b) {
  cout << "a = " << a << ",b = " << b << ",b+=1 = " << (b+=1) << endl;
}
void f3(int &&a, double &b) {
  cout << "a = " << a << ",b = " << b << endl;
}

int main() {
  int ival = 42;
  double dval = 3.14;
  // 调用参数类型是非引用类型的函数是可以的
  flip1(f1, 3.33, 42);
  // 没法改变dval的值
  flip1(f2, dval, 42);
  cout << "dval = " << dval << endl;
  // 实例化报错
  //flip1(f3, dval, 42);
  // ---------------------------------------------------------------------------------
  cout << "------------------------------" << endl;
  flip2(f1, 3.33, 42);
  // 通过使用类型为模板类型右值引用的参数，可以将实参的状态传递给里层函数
  flip2(f2, dval, 42);
  cout << "dval = " << dval << endl;
  // 但是flip2调用参数为右值引用的函数时，发生编译错误：即使我们传递的是一个右值
  // flip2(f3, dval, 42);
  flip3(f1, 3.33, 42);
  flip3(f2, dval, 42);
  cout << "dval = " << dval << endl;
  flip3(f3, dval, 42);
}
