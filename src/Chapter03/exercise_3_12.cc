#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<int>> ivec;        // OK
//    vector<string> svec = ivec;    // ERROR
    vector<string> svec(10, "null"); // OK
}
