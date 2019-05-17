#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
    string s;
    while (cin >> s && s != "nice") {}
    assert(cin);
}
