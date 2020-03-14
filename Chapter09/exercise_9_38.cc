#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec;
    cout << "Initially: size=" << ivec.size() << " capacity=" << ivec.capacity() << endl;
    for (vector<int>::size_type i = 0; i < 51; ++i) {
        ivec.push_back(i);
        cout << "Index[" << i << "]: size=" << ivec.size() << " capacity=" << ivec.capacity() << endl;
    }
}
