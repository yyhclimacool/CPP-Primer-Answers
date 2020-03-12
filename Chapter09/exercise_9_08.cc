#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> slst{"a", "an", "the"};
    list<string>::const_iterator it = slst.begin();
    cout << *it << endl;

    list<string>::iterator it2 = slst.begin();
    *it2 = "See?";
    cout << *slst.begin() << endl;
}
