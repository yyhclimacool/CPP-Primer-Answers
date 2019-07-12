#include <memory>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    unique_ptr<int> p1(new int(1024));
    unique_ptr<int> p2(p1);
}
