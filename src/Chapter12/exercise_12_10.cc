#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {
    cout << ptr.use_count() << endl;
}

int main() {
    shared_ptr<int> spi(new int(42));
    process(shared_ptr<int>(spi));
    process(shared_ptr<int>(new int(11)));
}
