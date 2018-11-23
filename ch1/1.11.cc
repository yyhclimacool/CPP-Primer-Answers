#include <iostream>

using namespace std;

int main() {
    cout << "Input two numbers : " << endl;
    int v1, v2;
    cin >> v1 >> v2;
    int min, max;
    if (v1 < v2) {
        min = v1;
        max = v2;
    } else {
        min = v2;
        max = v1;
    }
    while (min <= max) {
        cout << min << " ";
        ++min;
    }
    cout << endl;
}
