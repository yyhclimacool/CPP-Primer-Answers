#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class PersonInfo {
public:
    string name;
    vector<string> phones;
};

void read_records(const string &file) {
    ifstream ifs(file);
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(ifs, line)) {
        PersonInfo info;
        record.str(line);
//        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    ifs.close();
    std::cout << "Num of people: " << people.size() << std::endl;
}

int main(int argc, char **argv) {
    read_records(argv[1]);
}
