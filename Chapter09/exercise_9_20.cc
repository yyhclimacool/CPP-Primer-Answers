#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main() {
    list<int> ilst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> evens, odds;
    for (list<int>::const_iterator it = ilst.cbegin(); it != ilst.cend(); ++it) {
        if (((*it) % 2) == 0)
            evens.push_back(*it);
        else
            odds.push_back(*it);
    }
    cout << evens.size() << "," << odds.size() << endl;
    return 0;
}
