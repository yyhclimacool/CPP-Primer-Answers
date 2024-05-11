#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_08) {
    list<string> slst{"a", "an", "the"};
    list<string>::const_iterator it = slst.begin();
    cout << *it << endl;

    list<string>::iterator it2 = slst.begin();
    *it2 = "See?";
    cout << *slst.begin() << endl;
}
