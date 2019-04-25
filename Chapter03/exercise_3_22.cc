#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

int main() {
    vector<string> text = {"This line will be printed", "\n", "The second line", "the last LINE"};

    for (auto it = text.begin();
         it != text.end() && !it->empty();
         ++it) {
        for (string::iterator sit = it->begin(); sit != it->end(); ++sit)
            *sit = toupper(*sit);
        cout << *it << endl;
    }
}
