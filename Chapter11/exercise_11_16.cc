#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> mapper = {{"fine", 1}, {"nice", 2}};

    int ival = mapper.begin()->second;
    cout << ival << endl;
}
