#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

std::istream &read_print(const std::string &file) {
    ifstream is(file);
    std::string line;
    std::vector<std::string> line_vec;
    while(getline(is, line))
        line_vec.push_back(line);
    for (const auto &l : line_vec) {
        istringstream iss(l);
        std::string word;
        while(iss >> word)
            std::cout << word << std::endl;
    }
}

int main(int argc, char **argv) {
    read_print(argv[1]);
}
