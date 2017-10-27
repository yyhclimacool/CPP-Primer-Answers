#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    vector<double> dvec;
    double dval;
    while(cin >>dval){
        dvec.push_back(dval);
    }

    auto result = accumulate(dvec.cbegin(), dvec.cend(), 0);
    cout << "result is " << result << endl;
}
