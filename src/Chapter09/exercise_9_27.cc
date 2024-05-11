#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_27) {
    forward_list<int> iflst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    forward_list<int>::iterator prev = iflst.before_begin(),
                                curr = iflst.begin();

    while (curr != iflst.end()) {
        if (*curr % 2)
            curr = iflst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto e : iflst)
        cout << e << "\t";
    cout << endl;
}
