#include <iostream>

using namespace std;

class Point {
public:
    Point() = default;
    Point(const Point &) { std::cout << "Copy Constructor !" << std::endl; }
    Point &operator=(const Point &) = default;
    ~Point() = default;
};

Point global;

Point foo_bar(Point arg) {
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = {local, *heap};
    return *heap;
}

int main() {
    foo_bar(global);
    return 0;
}
