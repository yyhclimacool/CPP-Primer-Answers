#include "src/common.h"
using namespace std;

TEST(Chapter09, exercise_9_39) {
    vector<string> svec;
    svec.reserve(1024); // capacity = 1024
    string word;
    while (cin >> word) 
        svec.push_back(word);
    svec.resize(svec.size() + svec.size()/2); // value initialized
}
