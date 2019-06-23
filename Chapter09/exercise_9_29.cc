#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> ivec;
    for (int i = 0; i != 25; ++i)
        ivec.push_back(i);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;
    
    ivec.resize(100);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;

    ivec.resize(10);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;

    return 0;
}
