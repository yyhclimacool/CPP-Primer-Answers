#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    cout << "Enter some numbers:\t" << endl;
    istream_iterator<int> int_it(cin), eof;
    vector<int> ivec(int_it, eof);
    std::sort(ivec.begin(), ivec.end());
    copy(ivec.cbegin(), ivec.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
