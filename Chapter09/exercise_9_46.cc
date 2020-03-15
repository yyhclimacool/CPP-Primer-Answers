#include <string>
#include <iostream>

using namespace std;

string name_manip(string &name, const string &prefix, const string &sufix) {
    name.insert(0, prefix);
    name.insert(name.size(), sufix);

    return name;
}

int main() {
    string oriname = "Robert Downie";
    cout << name_manip(oriname, "Mr.", "Jr.") << endl;
}
