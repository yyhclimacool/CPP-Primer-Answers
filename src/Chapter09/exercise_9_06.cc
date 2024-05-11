#include "src/common.h"

TEST(Chapter09, exercise_9_06) {
    std::list<int> ilst;
    auto iter1 = ilst.begin();
    auto iter2 = ilst.end();
    // No operator< defined
    //if (iter1 < iter2) {
    //    std::cout << "You see me!" << std::endl;
    //}
}
