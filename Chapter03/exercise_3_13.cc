#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1;     // empty vector
    vector<int> v2(10); // 10 elements
    vector<int> v3(10, 42); // 10 elements of 42
    vector<int> v4{10};     // 1 element
    vector<int> v5{10, 42}; // 2 elements
    vector<string> v6{10};  // 10 elements of empty string
    vector<string> v7{10, "hi"}; // 10 elements of "hi"
}
