#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> iv{1,2,3,4,5,6,7,7,8,8,9,6,65,5,4,2};
    auto iter = iv.begin(), mid = iter + iv.size() / 2;
    while (iter != mid) {
        if (*iter == 3)
            iv.insert(iv.begin(), 2 * 3);
    }
}
