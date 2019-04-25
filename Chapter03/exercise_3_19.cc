#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> v2(10, 42);
    vector<int> v3;
    for (int i = 0; i < 10; ++i)
        v3.push_back(42);
}
