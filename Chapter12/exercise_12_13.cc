#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;
    cout << *sp << endl;
    // Core dump
}
