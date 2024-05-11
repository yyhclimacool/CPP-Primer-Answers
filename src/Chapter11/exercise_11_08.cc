#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> svec;
    string str;
    while (cin >> str) 
        svec.push_back(str);
    std::sort(svec.begin(), svec.end());
    auto end_unique = std::unique(svec.begin(), svec.end());
    svec.erase(end_unique, svec.end());
}
