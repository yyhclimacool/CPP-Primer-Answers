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

    // output
    cout << "v1.size() = " << v1.size() << " ";
    for (const auto &val : v1)
        cout << val << "\t";
    cout << std::endl;

    cout << "v2.size() = " << v2.size() << " ";
    for (const auto &val : v2) 
        cout << val << "\t";
    cout << std::endl; 

    cout << "v3.size() = " << v3.size() << " ";
    for (const auto &val : v3) 
        cout << val << "\t";
    cout << std::endl; 

    cout << "v4.size() = " << v4.size() << " ";
    for (const auto &val : v4) 
        cout << val << "\t";
    cout << std::endl; 

    cout << "v5.size() = " << v5.size() << " ";
    for (const auto &val : v5) 
        cout << val << "\t";
    cout << std::endl; 

    cout << "v6.size() = " << v6.size() << " ";
    for (const auto &val : v6) 
        cout << val << "\t";
    cout << std::endl;

    cout << "v7.size() = " << v7.size() << " ";
    for (const auto &val : v7) 
        cout << val << "\t";
    cout << std::endl; 
}
