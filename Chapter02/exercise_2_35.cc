#include <iostream>

int main() {
    const int i = 42;
    auto j = i; // j是个整型，i的顶层const被忽略
    const auto &k = i; // k是整型常量的引用
    auto *p = &i;      // p是指向整型常量的指针
    const auto j2 = i, &k2 = i; // j2是整型常量，k2是常量引用

    return 0;
}
