#include <iostream>

using namespace std;

class IfThenElse {
public:
    int operator()(bool cond, int lhs, int rhs) {
        return cond ? lhs : rhs;
    }
};

int main() {
    IfThenElse sentence;
    cout << sentence(true, 10, 42) << endl;
}
