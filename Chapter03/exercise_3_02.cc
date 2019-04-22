#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main() {
    string line, word;
    while(getline(cin, line))
        cout << line << endl;

    cin.clear();

    while(cin >> word)
        cout << word << endl;

    return 0;
}
