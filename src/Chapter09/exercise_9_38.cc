#include "src/common.h"
using namespace std;

TEST(Chapter09, exercise_9_38) {
    vector<int> ivec;
    cout << "Initially: size=" << ivec.size() << " capacity=" << ivec.capacity() << endl;
    for (vector<int>::size_type i = 0; i < 51; ++i) {
        ivec.push_back(i);
        cout << "Index[" << i << "]: size=" << ivec.size() << " capacity=" << ivec.capacity() << endl;
    }
}
