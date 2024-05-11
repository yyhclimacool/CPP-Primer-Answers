#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo() = default;
    Foo(initializer_list<int> il) : data(il) {}

    Foo sorted() && {
        cout << "Calling Foo sorted() && ..." << endl;
        std::sort(data.begin(), data.end());
        return *this;
    }

    Foo sorted() const & {
        cout << "Calling Foo sorted() const & ..." << endl;
        // 这是OK的，这里用的临时对象
        return Foo(*this).sorted();
    }
private:
    vector<int> data;
};

Foo f_global{1,2,3,4,5};

Foo &fcn1() {
    return f_global;
}

Foo fcn2() {
    return Foo{6,7,8,9,0};
}

int main() {
    fcn1().sorted();
    fcn2().sorted();
}
