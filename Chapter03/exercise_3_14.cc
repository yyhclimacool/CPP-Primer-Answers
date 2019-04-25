#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> ivec;
    int val = 0;
    while (cin >> val) 
        ivec.push_back(val);
    cout << ivec.size() << endl;

    return 0;
}
