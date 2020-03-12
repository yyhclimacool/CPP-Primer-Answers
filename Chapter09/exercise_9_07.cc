#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec{1,2,3,4,5,6,7,8,8};
    for(vector<int>::size_type i = 0; i != ivec.size(); ++i) {
        cout << ivec[i] << " ";
    }
    cout << endl;
}
