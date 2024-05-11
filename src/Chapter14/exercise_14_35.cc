#include <iostream>
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
    cout << rs() << endl;
}
