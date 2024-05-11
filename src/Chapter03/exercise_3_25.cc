#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> scores(11, 0);
    auto beg = scores.begin();
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++(*(beg + grade/10));
    }

    for (const auto &ele : scores)
        cout << ele << "\t";
    cout << endl;
}
