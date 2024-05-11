#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_11) {
    vector<int> ivec1; // empty
    vector<int> ivec2{1,2,3,4,5,6,7,8,9,0}; // 10 elements
    vector<int> ivec3(ivec2); // same as ivec2
    vector<int> ivec4(ivec2.begin(), ivec2.end()); // same as ivec2
    vector<int> ivec5(10);
    vector<int> ivec6(10, 42);
}
