#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool isShorter(const string &lhs, const string &rhs) {
    return lhs.size() < rhs.size();
}

bool check5(const string &s) {
    return s.size() < 5;
}

void elimDups(vector<string> &words) {
//    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
//    cout << endl;

    sort(words.begin(), words.end());

    auto end_unique = unique(words.begin(), words.end());

//    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
//    cout << endl;

    words.erase(end_unique, words.end());

//    for_each(words.cbegin(), words.cend(), [] (const string &s) { cout << s << '\t'; });
//    cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &lhs, const string &rhs) 
                    { return lhs.size() < rhs.size(); });
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() < sz; });
    auto count = words.end() - wc;
    cout << count << " " << " words "" of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s) { cout << s << ' '; });
    cout << endl;
}

int main() {
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    biggies(svec, 5);
    biggies(svec, 6);

    return 0;
}
