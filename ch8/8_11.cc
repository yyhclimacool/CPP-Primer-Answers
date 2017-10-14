#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> numbers;
};

void read_person(const string &info_file){
    ifstream ifs(info_file);
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(ifs, line)){
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while(record >> word)
            info.numbers.push_back(word);
        people.push_back(info);
    }

#ifndef NDEBUG
    cout << "File name: " << __FILE__ << " - Function name: " << __func__\
        << "num of rows: " << people.size() << endl;
#endif
}

int main(int argc, char **argv){
    if(argc < 2)
        cerr << "Usage: " << argv[0] << "<file>" << endl;

    read_person(argv[1]);
}
