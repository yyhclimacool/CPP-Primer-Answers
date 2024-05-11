#include "src/common.h"
using namespace std;

bool find_in_vec(vector<int>::const_iterator beg, vector<int>::const_iterator end, int val) {
    for (auto it = beg; it != end; ++it)
        if (*it == val)
            return true;
    return false;
}

TEST(Chapter09, exercise_9_04) {
    vector<int> ivec = {23, 34, 1, 45, 65, 2, 6, 7, 90, 84, 63, 33};
    std::cout << find_in_vec(ivec.begin(), ivec.end(), 90) << std::endl;
    std::cout << find_in_vec(ivec.begin() + 3, ivec.end(), 23) << std::endl;
    std::cout << find_in_vec(ivec.begin() + 4, ivec.begin() + 4, 65) << std::endl;
}
