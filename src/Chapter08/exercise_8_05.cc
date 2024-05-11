#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

auto func(const string &infile) -> vector<string> {
    vector<string> svec;
    ifstream ifs(infile);
    string line;
    while(ifs >> line) 
        svec.push_back(line);
    return svec;
}

int main(int argc, char **argv) {
    auto a = func(argv[1]);
    for (auto &e : a) 
        std::cout << "---- " << e << std::endl;
}
