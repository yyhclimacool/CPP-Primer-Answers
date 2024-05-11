#include <iostream>

using namespace std;

int main() {
    const string s = "Keep out!";
    for (auto &c : s) {
        //c = 'a'; // error: assignment of read-only reference ‘c’
        cout << c;
    }
    cout << endl;
}
