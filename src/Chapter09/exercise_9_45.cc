#include "src/common.h"
using namespace std;

string name_manip(string &name, const string &prefix, const string &sufix) {
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(sufix);
    return name;
}

TEST(Chapter09, exercise_9_45) {
    string oriname = "Robert Downie";
    cout << name_manip(oriname, "Mr.", "Jr.") << endl;
}
