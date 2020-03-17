#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;
    string line, word;
    while (map_file >> word && getline(map_file, line)) {
        if (line.size() > 1)
            //trans_map[word] = line.substr(1);
            trans_map.insert({word, line.substr(1)});
        else
            throw runtime_error("No rule for " + word);
    }
    return trans_map;
}

std::string transform(const string &word, const map<string, string> &trans_map) {
    auto it = trans_map.find(word);
    if (it == trans_map.end())
        return word;
    else
        return it->second;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text)) {
        istringstream iss(text);
        string word;
        bool first_word = true;
        while (iss >> word) {
            if (first_word)
                first_word = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) 
        cerr << "Usage: " << argv[0] << " map_file input_file" << endl;
    ifstream map_ifs(argv[1]);
    ifstream input_ifs(argv[2]);
    word_transform(map_ifs, input_ifs);
}
