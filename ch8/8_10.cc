#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void read_and_print(const string &infile){
    ifstream ifs(infile);
    vector<string> lines;
    string a_line;
    while(getline(ifs, a_line)){
        lines.push_back(a_line);
    }
#ifndef NDEBUG
    cout << "File name: " << __FILE__ << " - Function name: " << \
        __func__ << " - lines.size(): " << lines.size() << endl;
#endif
    for (auto &elem : lines){
        istringstream iss(elem);
        string word;
        while(iss >> word)
            cout << word << "\t";
    }
}

int main(int argc, char **argv){
    if(argc < 2)
        cerr << "Usage: " << argv[0] << " <file>";

    read_and_print(argv[1]);
}
