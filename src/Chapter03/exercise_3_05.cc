#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main() {
    string result, word;
    while(cin >> word)
        result += word;

    cout << result << endl;

    cin.clear();
    while(cin >> word)
        result = result + ' ' + word;

    cout << result << endl;

    return 0;
}
