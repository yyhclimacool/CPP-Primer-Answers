#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int main() {
    cout << "Read file '/etc/legal'" << endl;
    ifstream ifs("/etc/legal");
    istream_iterator<string> in_it(ifs), eof;
    vector<string> svec(in_it, eof);
    copy(svec.cbegin(), svec.cend(), ostream_iterator<string>(cout, "\n"));
}
