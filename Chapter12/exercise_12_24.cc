#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    char *stra = new char[str.size() + 1]();
    for (size_t i = 0; i < str.size(); ++i) {
        stra[i] = str[i];
    }
    cout << stra << endl;
    delete [] stra;
}
