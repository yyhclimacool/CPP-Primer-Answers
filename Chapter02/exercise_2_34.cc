#include <iostream>

int main() {
    int i = 0, &r = i;
    auto a = r;  // a是一个整数(r是i的别名，而i是一个整数)

    const int ci = i, &cr = ci;
    auto b = ci;  // b是一个整数(ci的顶层const特性被忽略掉了)
    auto c = cr;  // c是一个整数(cr是ci的别名,ci本身是一个顶层const)
    auto d = &i;  // d是一个整型指针(整数的地址就是指向整数的指针)
    auto e = &ci;  // e是一个指向整数常量的指针(对常量对象取地址是一种底层const)

    const auto f = ci;  // 如果希望推断出的auto类型是一个顶层const，需要明确指出

    auto &g = ci; // g是一个整型常量引用，绑定到ci
//    auto &h = 42; // 错误：不能为非常量引用绑定字面值
    const auto &j = 42; // 正确：可以为常量引用绑定字面值

    a = 42; // OK
    b = 42; // OK
    c = 42; // OK
//    d = 42; // oops
//    e = 42; // oops
//    g = 42; // oops

    return 0;
}
