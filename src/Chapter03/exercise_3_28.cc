#include <string>
#include <iostream>

using namespace std;

string sa[10];
int ia[10];

int main() {
    string sa2[10];
    int ia2[10]; // Danger : value not sure

    // output
    for (size_t i = 0; i < 10; ++i) {
        cout << sa[i] << ',' << ia[i] << ',' << sa2[i] << ',' << ia2[i] << ',' <<  endl;
    }
}
