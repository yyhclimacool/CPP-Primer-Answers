#include <map>
#include <iostream>

using namespace std;

void word_count(istream &is) {
    map<string, size_t> word_count;
    string word;
    while (is >> word) {
        auto res = word_count.insert(make_pair(word, 1));
        if (!res.second)
            ++res.first->second;
    }

    // output
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << " times" << endl;
}

int main() {
    word_count(cin);
}
