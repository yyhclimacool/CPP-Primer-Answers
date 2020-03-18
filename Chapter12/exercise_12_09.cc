#include <memory>
#include <iostream>

using namespace std;

int main() {
    int *q = new int(42), *r = new int(100);
    delete r;
    r = q;
    cout << "*r = " << *r << ", *q = " << *q << endl;

    auto q2 = make_shared<int>(42), r2 = make_shared<int>(1000);
    r2 = q2;
    cout << "q2.use_count() = " << q2.use_count() << endl;
}
