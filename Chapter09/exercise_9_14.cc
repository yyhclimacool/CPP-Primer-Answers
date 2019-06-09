#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main() {
    list<const char *> cplst = {"this", "is", "a", "line"};
    vector<string> svec(cplst.begin(), cplst.end());
    for (const auto &e : svec)
        std::cout << e << std::endl;
}
