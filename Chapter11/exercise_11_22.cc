#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<string, vector<int>> the_map;
    std::pair<std::map<string, vector<int>>::iterator, bool> res = the_map.insert({"hello", {1,2,3,4}});
    cout << "Insert success or not: " << res.second << endl;
}
