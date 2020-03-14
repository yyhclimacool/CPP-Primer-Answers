#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    str.resize(100);
    for (int i = 0; i < 100; ++i) 
        str[i] = 'a';
    cout << str << ":" << str.size() << endl;
}
