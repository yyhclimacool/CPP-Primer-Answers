#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    map<string, int> word_cnt = {{"fine", 1}, {"good", 5}};
    string str = "fine";
    int ival = word_cnt[str];
    cout << ival << endl;
}
