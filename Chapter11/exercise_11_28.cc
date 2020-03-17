#include <map>
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    map<string, vector<int>> the_map = {{"No.1", {1,2,3,4}}, {"No.2", {2,3,4,5}}};
    map<string, vector<int>>::iterator it = the_map.find("No.2");
    cout << it->first << endl;
    std::copy(it->second.cbegin(), it->second.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
