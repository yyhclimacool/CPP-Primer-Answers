#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_11) {
  vector<int> ivec1; // empty
  ASSERT_EQ(ivec1.size(), 0);
  vector<int> ivec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // 10 elements
  ASSERT_EQ(ivec2.size(), 10);
  vector<int> ivec3(ivec2); // same as ivec2
  ASSERT_EQ(ivec3, ivec2);
  vector<int> ivec4(ivec2.begin(), ivec2.end()); // same as ivec2
  ASSERT_EQ(ivec4, ivec2);
  vector<int> ivec5(10);
  ASSERT_EQ(ivec5.size(), 10);
  ASSERT_EQ(ivec5.front(), 0);
  vector<int> ivec6(10, 42);
  ASSERT_EQ(ivec6.back(), 42);
}
