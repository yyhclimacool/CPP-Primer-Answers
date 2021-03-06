#include <vector>
#include <iostream>

using namespace std;

vector<int>::const_iterator find_in_vec(vector<int>::const_iterator beg, vector<int>::const_iterator end, int val) {
    for (auto it = beg; it != end; ++it)
        if (*it == val)
            return it;
    return end;
}

int main() {
    vector<int> ivec = {23, 34, 1, 45, 65, 2, 6, 7, 90, 84, 63, 33};
    std::cout << (find_in_vec(ivec.begin(), ivec.end(), 90) != ivec.end() ? *(find_in_vec(ivec.begin(), ivec.end(), 90)) : -1 )<< std::endl;
//    std::cout << find_in_vec(ivec.begin() + 3, ivec.end(), 23) << std::endl;
//    std::cout << find_in_vec(ivec.begin() + 4, ivec.begin() + 4, 65) << std::endl;
}
