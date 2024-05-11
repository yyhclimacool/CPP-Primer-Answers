#include "src/common.h"
using namespace std;

void find_insert(forward_list<string> &sflst, const string &lhs, const string &rhs) {
    forward_list<string>::iterator prev = sflst.before_begin(),
                                   curr = sflst.begin();
    bool found = false;
    while (curr != sflst.end()) {
        if (*curr == lhs) {
            curr = sflst.insert_after(curr, rhs);
            ++curr;
            found = true;
        } else {
            prev = curr;
            ++curr;
        }
    }
    if (!found && curr == sflst.end()) {
        sflst.insert_after(prev, rhs);
    }
}

TEST(Chapter09, exercise_9_28) {
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
