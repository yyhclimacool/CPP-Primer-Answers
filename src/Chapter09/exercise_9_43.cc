#include "src/common.h"

bool myReplace(std::string &s, const std::string &oldValue, const std::string &newValue) {
    bool replaced = false;
    std::string::size_type pos = s.find(oldValue);
    while (pos != std::string::npos) {
        std::string::iterator itr = s.begin() + pos;
        itr = s.erase(itr, itr + oldValue.size());
        itr = s.insert(itr, newValue.begin(), newValue.end());
        itr += newValue.size();
        pos = itr - s.begin();
        pos = s.find(oldValue, pos);
        replaced = true;
    }

    return replaced;
}

TEST(Chapter09, exercise_9_43) {
    std::string oris = "This a string contains tho and thru, thothotho thru";
    myReplace(oris, "tho", "though");
    myReplace(oris, "thru", "through");
    std::cout << oris << std::endl;
}
