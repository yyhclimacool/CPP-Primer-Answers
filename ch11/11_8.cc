#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> svec;
    string sval;
    cout << "Enter some strings:" << endl;
    while(cin >> sval){
        if(find(svec.cbegin(), svec.cend(), sval) == svec.cend())
            svec.push_back(sval);
        else
            cout << "Already have: " << sval << endl;
    }

    for(const auto &elem : svec)
        cout << elem << endl;
}
