#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_02) {
    list<deque<int>> lst;
    EXPECT_EQ(0, lst.size());
    EXPECT_EQ(0, lst.max_size());
    EXPECT_TRUE(lst.empty());
    lst.push_back({1, 2, 3});
    EXPECT_EQ(1, lst.size());
    EXPECT_EQ(1, lst.max_size());
}
