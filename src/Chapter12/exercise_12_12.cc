#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {
    cout << ptr.use_count() << endl;
}

int main() {
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);
    process(shared_ptr<int>(new int()));
    //process(p);
    process(shared_ptr<int>(p));
    cout << *p << endl; // ERROR
}
