#include "src/common.h"

using namespace std;

void myReplace1(string &s, const std::string &oldValue, const std::string &newValue) {
    string::size_type pos = s.find(oldValue);
    while (pos != string::npos) {
        s.replace(pos, oldValue.size(), newValue);
        pos += newValue.size();
        pos = s.find(oldValue, pos);
    }
}

TEST(Chapter09, exercise_9_44) {
    std::string oris = "This a string contains tho and thru, thothotho thru";
    myReplace1(oris, "tho", "though");
    myReplace1(oris, "thru", "through");
    std::cout << oris << std::endl;
}
