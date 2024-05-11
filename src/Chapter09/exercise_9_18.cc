#include "src/common.h"

using namespace std;

TEST(Chapter09, exercise_9_18) {
    deque<string> sq;
    string temp_str;
    while (cin >> temp_str)
        sq.push_back(std::move(temp_str));

    for (auto it = sq.cbegin(); it != sq.cend(); ++it) 
        cout << *it << "\t";
    cout << endl;
}
