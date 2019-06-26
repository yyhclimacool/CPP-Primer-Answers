#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool isShorter(const string &lhs, const string &rhs) {
    return lhs.size() < rhs.size();
}

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

    stable_sort(svec.begin(), svec.end(), isShorter);
    for_each(svec.cbegin(), svec.cend(), [](const string &s) { cout << s << ' '; });
    cout << endl;

    return 0;
}
