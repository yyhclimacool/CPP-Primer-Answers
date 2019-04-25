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
    for (vector<int>::const_iterator cit = v1.cbegin(); cit != v1.cend(); ++cit)
        cout << *cit << '\t';
    cout << endl;

    cout << "v2.size() = " << v2.size() << " ";
    for (auto cit = v2.cbegin(); cit != v2.cend(); ++cit)
        cout << *cit << '\t';
    cout << std::endl; 

    cout << "v3.size() = " << v3.size() << " ";
    for (auto cit = v3.cbegin(); cit != v3.cend(); ++cit) 
        cout << *cit << '\t';
    cout << std::endl; 

    cout << "v4.size() = " << v4.size() << " ";
    for (auto cit = v4.cbegin(); cit != v4.cend(); ++cit)
        cout << *cit << '\t';
    cout << std::endl; 

    cout << "v5.size() = " << v5.size() << " ";
    for (auto cit = v5.cbegin(); cit != v5.cend(); ++cit)
        cout << *cit << "\t";
    cout << std::endl; 

    cout << "v6.size() = " << v6.size() << " ";
    for (auto cit = v6.cbegin(); cit != v6.cend(); ++cit)
        cout << *cit << "\t";
    cout << std::endl;

    cout << "v7.size() = " << v7.size() << " ";
    for (auto cit = v7.cbegin(); cit != v7.cend(); ++cit)
        cout << *cit << "\t";
    cout << std::endl; 
}
