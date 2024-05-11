#include "src/common.h"
using namespace std;

TEST(Capacity, exercise_9_31) {
    list<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> iflst(nums.begin(), nums.end());

    for (auto &e : nums)
        cout << e << '\t';
    cout << endl;

    auto iter = nums.begin();
    while (iter != nums.end()) {
        if (*iter % 2) {
            iter = nums.insert(iter, *iter);
            ++(++iter);
        } else
            iter = nums.erase(iter);
    }

    for (auto &e : nums)
        cout << e << '\t';
    cout << endl;


    cout << "forward_list : " << std::endl;
    for (auto &e : iflst)
        cout << e << '\t';
    cout << endl;

    forward_list<int>::iterator prev = iflst.before_begin(),
                                curr = iflst.begin();
    while (curr != iflst.end()) {
        if (*curr % 2) {
            curr = iflst.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        } else {
            ++curr;
            iflst.erase_after(prev);
        }
    }

    for (auto &e : iflst)
        cout << e << '\t';
    cout << endl;
}
