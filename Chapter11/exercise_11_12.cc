#include <string>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

void func(istream &is) {
    string str;
    int ival;
    vector<pair<string, int>> vec_of_pair;
    while (is >> str >> ival) {
        vec_of_pair.push_back(make_pair(str, ival));
    }

    for (const auto &e : vec_of_pair)
        cout << e.first << "--->" << e.second << endl;
}

int main() {
    func(cin);
}
