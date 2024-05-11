#include <map>
#include <iostream>
#include <string>

using namespace std;

void word_count(istream &is) {
    map<string, size_t> word_count;
    string word;
    while (is >> word)
        ++word_count[word];
    // output
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << " times" << endl;
}

int main() {
    word_count(cin);
}
