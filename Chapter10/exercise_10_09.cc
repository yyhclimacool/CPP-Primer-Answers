#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void elimDups(vector<string> &words) {
    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;

    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;

    words.erase(end_unique, words.end());

    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
    cout << endl;
}

int main() {
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(svec);

    return 0;
}
