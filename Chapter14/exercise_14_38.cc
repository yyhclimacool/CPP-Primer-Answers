#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SizeCmp {
public:
    SizeCmp(size_t sz) : sz_(sz) {}
    bool operator()(const std::string &str) const {
        return str.size() == sz_;
    }
private:
    size_t sz_;
};

int main() {
    vector<string> svec = {"a", "an", "the", "fine", "be", "not"};
    SizeCmp sc(2);
    for (const auto &e : svec)
        if (sc(e))
            cout << e << endl;
}
