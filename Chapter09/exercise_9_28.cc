#include <string>
#include <iostream>
#include <forward_list>

using namespace std;

void find_insert(forward_list<string> &sflst, const string &lhs, const string &rhs) {
    forward_list<string>::iterator prev = sflst.before_begin(),
                                   curr = sflst.begin();
    ++prev, ++curr;
    bool found = false;
    while (prev != sflst.end()) {
        if (*prev == lhs) {
            prev = sflst.insert_after(prev, rhs);
            found = true;
        }
        if (!found && (it + 1) == sflst.end()) {
            it = sflst.insert_after(it, rhs);
        }
        ++it;
    }
}

int main() {
    forward_list<string> sflst = {"we", "are", "the", "champion", "and", "we", "will", "fight", "till", "the", "end"};
    for (const auto & e: sflst)
        cout << e << ", ";
    cout << endl;

    find_insert(sflst, "we", "bang");

    for (const auto & e: sflst)
        cout << e << ", ";
    cout << endl;

    find_insert(sflst, "loser", "win!");

    for (const auto & e: sflst)
        cout << e << ", ";
    cout << endl;
}
