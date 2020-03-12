#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec{1,2,3,4,5,5,67,8,9,45};
    cout << "using at " << ivec.at(0) << endl;
    cout << "using index " << ivec[0] << endl;
    cout << "using front " << ivec.front() << endl;
    cout << "using begin " << *ivec.begin() << endl;
    cout << "using back  " << ivec.back() << endl;

    vector<int> ivec_empty;
    cout << "using at " << ivec_empty.at(0) << endl;
    cout << "using index " << ivec_empty[0] << endl;
    cout << "using front " << ivec_empty.front() << endl;
    cout << "using begin " << *ivec_empty.begin() << endl;
    cout << "using back  " << ivec_empty.back() << endl;
}
