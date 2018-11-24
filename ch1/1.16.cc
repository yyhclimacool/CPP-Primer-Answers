#include <iostream>

using namespace std;

int main() {
    int sum = 0, ival = 0;
    while(cin >> ival) 
        sum += ival;
    cout << "Sum is " << sum << endl;
}
