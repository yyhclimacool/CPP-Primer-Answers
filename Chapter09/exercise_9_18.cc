#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<string> sq;
    string temp_str;
    while (cin >> temp_str)
        sq.push_back(std::move(temp_str));

    for (auto it = sq.cbegin(); it != sq.cend(); ++it) 
        cout << *it << "\t";
    cout << endl;
}
