#include <string>
#include <iostream>

using namespace std;

string name_manip(string &name, const string &prefix, const string &sufix) {
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(sufix);
    return name;
}

int main() {
    string oriname = "Robert Downie";
    cout << name_manip(oriname, "Mr.", "Jr.") << endl;
}
