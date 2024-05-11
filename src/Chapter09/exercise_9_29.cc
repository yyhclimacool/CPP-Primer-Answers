#include "src/common.h"
using namespace std;

TEST(Chapter09, exercise_9_29) {
    vector<int> ivec;
    for (int i = 0; i != 25; ++i)
        ivec.push_back(i);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;
    
    ivec.resize(100);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;

    ivec.resize(10);
    cout << "size: " << ivec.size() << ", Capacity: " << ivec.capacity() << endl;
}
