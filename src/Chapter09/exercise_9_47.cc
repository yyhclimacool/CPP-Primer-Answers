#include "src/common.h"
using namespace std;

TEST(Chapter09, exercise_9_47) {
    string oris = "ab2c3d7R4E6";
    string alphas;
    for (char c = 'a'; c != 'a' + 26; ++c)
        alphas.push_back(c);
    for (char c = 'A'; c != 'A' + 26; ++c)
        alphas.push_back(c);
    string nums = "1234567890";

    string::size_type pos = oris.find_first_of(nums);
    while (pos != string::npos) {
        cout << "Found num " << oris[pos] << endl;
        pos = oris.find_first_of(nums, pos+1);
    }
    string::size_type alpha_pos = 0;
    while ((alpha_pos = oris.find_first_not_of(nums, alpha_pos)) 
            != string::npos) {
        cout << "Found alpha " << oris[alpha_pos] << endl;
        alpha_pos++;
    }
}
