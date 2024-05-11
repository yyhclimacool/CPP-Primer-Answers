#include <map>
#include <iostream>
#include <cctype>

using namespace std;

void word_count(istream &is) {
    map<string, size_t> word_count;
    string word;
    while (is >> word) {
        for (auto &e : word) {
            e = tolower(e);
            if (ispunct(e))
                e = '\0';
        }
        string temp = word;
        ++word_count[temp];
    }
    // output
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << " times" << endl;
}

int main() {
    word_count(cin);
}
