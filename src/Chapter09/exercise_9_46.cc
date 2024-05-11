#include "src/common.h"
using namespace std;

string name_manip1(string &name, const string &prefix, const string &sufix) {
    name.insert(0, prefix);
    name.insert(name.size(), sufix);

    return name;
}

TEST(Chapter09, exercise_9_46) {
    string oriname = "Robert Downie";
    cout << name_manip1(oriname, "Mr.", "Jr.") << endl;
}
