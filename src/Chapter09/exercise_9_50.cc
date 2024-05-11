#include "src/common.h"

using namespace std;

int add_ints(const vector<string> &values) {
    int sum = 0;
    std::for_each(values.cbegin(), values.cend(), [&](const std::string &val) { int i = stoi(val); sum +=i;});
    cout << sum << endl;
}

int add_doubles(const vector<string> &values) {
    double sum = 0;
    std::for_each(values.cbegin(), values.cend(), [&](const std::string &val) { double i = stod(val); sum +=i;});
    cout << sum << endl;
}

TEST(Chapter09, exercise_9_50) {
    vector<string> values{"12", "13", "90"};
    add_ints(values);
    vector<string> d_values{"1.23", "2.34", "3.45", "4.56"};
    add_doubles(d_values);
}
