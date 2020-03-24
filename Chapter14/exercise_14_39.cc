#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SizeCmp {
public:
    SizeCmp(size_t min, size_t max) : min_(min), max_(max) {}
    bool operator()(const std::string &str) const {
        return str.size() >= min_ && str.size() <= max_;
    }
private:
    size_t min_;
    size_t max_;
};

int main() {
    vector<string> svec = {"a", "an", "the", "fine", "be", "not"};
    SizeCmp sc(1, 9);
    for (const auto &e : svec)
        if (sc(e))
            cout << e << endl;
}
