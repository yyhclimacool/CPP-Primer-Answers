#include <iostream>

using namespace std;

class Point{
public:
    Point() = default;
    Point(const Point &p) : x(p.x) { cout << "Copy ctor" << endl; }
    int x;
};

Point global;

// 用实参初始化形参一次
Point foo_bar(Point arg) {
    // 拷贝构造local一次，new一个对象时一次
    Point local = arg, *heap = new Point(global);
    // 这里调用的是拷贝赋值运算符
    *heap = local;
    // 列表初始化ia的前两个元素时分别调用一次
    Point ia[4] = {local, *heap};
    // 非引用函数返回类型一次
    return *heap;
}// 共调用拷贝构造函数6次

int main() {
    Point p;
    foo_bar(p);
    return 0;
}
