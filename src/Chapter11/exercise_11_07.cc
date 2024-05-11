#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Family {
public:
    void addFamily(const string &lastname) {
        families_[lastname] = vector<string>();
    }

    void addChild(const string &lastname, const string &childname) {
        auto &children = families_[lastname];
        children.push_back(childname);
    }
    const map<string, vector<string>> &families() const {
        return families_;
    }

    map<string, vector<string>> &families() {
        return families_;
    }
private:
    map<string, vector<string>> families_;
};

ostream &operator<<(ostream &os, const Family &f) {
    for (const auto &e : f.families()) {
        os << e.first << " with children : \n";
        for (const auto &n : e.second)
            os << "\t" << n << '\n';
        os << endl;
    }
    return os;
}

int main() {
    Family fm;
    fm.addFamily("Chen");
    fm.addFamily("You");
    fm.addFamily("Huang");

    fm.addChild("You", "yunhong");
    fm.addChild("You", "hongyan");

    cout << fm << endl;
}
