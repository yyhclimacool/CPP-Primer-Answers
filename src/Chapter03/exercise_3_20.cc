#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec;
    int ival;

    while(cin >> ival)
        ivec.push_back(ival);

    for (decltype(ivec.size()) idx = 0; idx < ivec.size(); ++idx) {
        if (idx + 1 == ivec.size())
            cout << ivec[idx] << '\t';
        else 
            cout << ivec[idx] + ivec[++idx] << '\t';
    }
    cout << endl;

    for (decltype(ivec.size()) first = 0, last = ivec.size() - 1; first <= last; ++first, --last) {
        if (first == last)
            cout << ivec[first] << '\t';
        else
            cout << ivec[first] + ivec[last] << '\t';
    }
    cout << endl;
}
