#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void printAll(const std::multimap<std::string, std::set<std::string>> &authors) {
    for (const auto & elem : authors) {
        cout << elem.first << "\t";
        for (const auto &e : elem.second)
            cout << e << "|";
        cout << endl;
    }
}

int main() {
    std::multimap<string, set<string>> authors = {
        {"Alan de boton", {"aaa", "bbb", "ccc"}},
        {"Alan lu", {"ddd", "eee", "fff"}}
    };

    printAll(authors);
}
