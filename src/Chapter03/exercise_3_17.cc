#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    vector<string> svec;
    string sval;
    while (cin >> sval)
        svec.push_back(sval);

    for (auto &str : svec)
        for (auto &c : str)
            c = toupper(c);

    for (const auto &str : svec)
        cout << str << endl;

    return 0;
}
