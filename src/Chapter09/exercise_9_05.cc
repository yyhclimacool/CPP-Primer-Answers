#include "src/common.h"

using namespace std;

vector<int>::const_iterator find_in_vec1(vector<int>::const_iterator beg,
                                         vector<int>::const_iterator end,
                                         int val) {
  for (auto it = beg; it != end; ++it)
    if (*it == val)
      return it;
  return end;
}

TEST(Chapter09, exercise_9_05) {
  vector<int> ivec = {23, 34, 1, 45, 65, 2, 6, 7, 90, 84, 63, 33};
  ASSERT_TRUE(find_in_vec1(ivec.begin(), ivec.end(), 90) != ivec.end());
}
