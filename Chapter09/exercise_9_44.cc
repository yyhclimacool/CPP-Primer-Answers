#include <string>
#include <iostream>

using namespace std;

void myReplace(string &s, const std::string &oldValue, const std::string &newValue) {
    string::size_type pos = s.find(oldValue);
    while (pos != string::npos) {
        s.replace(pos, oldValue.size(), newValue);
        pos += newValue.size();
        pos = s.find(oldValue, pos);
    }
}

int main() {
    std::string oris = "This a string contains tho and thru, thothotho thru";
    myReplace(oris, "tho", "though");
    myReplace(oris, "thru", "through");
    std::cout << oris << std::endl;
}
