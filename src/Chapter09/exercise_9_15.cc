#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_15) {
    vector<int> ivec1 = {1,2,3,4,5,6};
    vector<int> ivec2(ivec1);
    if (ivec1 == ivec2)
        std::cout << "Equal" << std::endl;
    else
        std::cout << "Not equal" << std::endl;
}
