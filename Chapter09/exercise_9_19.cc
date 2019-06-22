#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> sq;
    string temp_str;
    while (cin >> temp_str)
        sq.push_back(std::move(temp_str));

    for (auto it = sq.cbegin(); it != sq.cend(); ++it) 
        cout << *it << "\t";
    cout << endl;
}
