#include <string>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    list<string> slst{"fine", "by", "me", "how", "are", "you", "fine", "thank", "you"};

    cout << "you : " << count(slst.begin(), slst.end(), "you") << endl;
    cout << "fine: " << count(slst.begin(), slst.end(), "fine") << endl;

    return 0;
}
