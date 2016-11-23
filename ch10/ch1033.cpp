#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void split(string digits, string odds, string even){
    ifstream ifs(digits);
    istream_iterator<int> infs_iter(ifs), eof;
    ofstream odd_ofs(odds, ofstream::app), even_ofs(even, ofstream::app);
    ostream_iterator<int> odd_ofs_iter(odd_ofs, " "), even_ofs_iter(even_ofs, "\n");

    vector<int> ivec(infs_iter, eof);
    copy_if(ivec.begin(), ivec.end(), odd_ofs_iter, [](int i){ return i%2 ? true:false; });
    copy_if(ivec.begin(), ivec.end(), even_ofs_iter, [](int i) { return i%2 ? false:true; });
}

int main(int argc, char **argv){
    if(argc != 4){
        cerr << "Usage: a <digits_file> <odds_file> <even_file>" << endl;
        return -1;
    }
    
    split(argv[1], argv[2], argv[3]);
    
    return 0;
}
