#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_42) {
    string str;
    str.resize(100);
    for (int i = 0; i < 100; ++i) 
        str[i] = 'a';
    cout << str << ":" << str.size() << endl;
}
