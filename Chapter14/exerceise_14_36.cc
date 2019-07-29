#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ReadString {
public:
    ReadString(istream &is = cin, const string &str = "") : istr_(is), str_(str) {}
    string operator()() {
        cout << "Input a line" << endl;
        getline(istr_, str_);
        if (!istr_)
            return "";
        return str_;
    }
private:
    istream &istr_;
    string str_;
};

int main() {
    ReadString rs;
    vector<string> svec;
    for (int i = 0; i != 10; ++i) {
        svec.push_back(std::move(rs()));
    }

    for (const auto & e : svec)
        cout << "line :" << e << endl;
}
