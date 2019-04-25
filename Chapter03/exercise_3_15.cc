#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
    vector<string> svec;
    string sval = 0;
    while (cin >> sval) 
        svec.push_back(sval);
    cout << svec.size() << endl;

    return 0;
}
