#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool isShorter(const string &lhs, const string &rhs) {
    return lhs.size() < rhs.size();
}

bool check5(const string &s) {
    return s.size() < 5;
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &lhs, const string &rhs) 
                    { return lhs.size() < rhs.size(); });
    auto wc = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() < sz; });
    auto check_sz = bind(check_size, _1, sz); 
    auto count = count_if(words.begin(), words.end(), check_sz);
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
