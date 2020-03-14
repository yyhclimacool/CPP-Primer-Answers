#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> cvec{'1', '2', '3', '4', '5'};
    string str_from_vec_char(&cvec[0], cvec.size());
    cout << str_from_vec_char << endl;
}
