#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_14) {
    list<const char *> cplst = {"this", "is", "a", "line"};
    vector<string> svec(cplst.begin(), cplst.end());
    for (const auto &e : svec)
        std::cout << e << std::endl;
}
