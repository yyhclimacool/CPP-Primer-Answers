#include <map>
#include <string>
#include <string>
#include <iostream>

using namespace std;

int main() {
    map<string, int> word_count = {{"fine", 1}, {"good", 8}};
    map<string, int>::iterator it = word_count.find("fine");
    cout << it->first << ',' << it->second << endl;
}
