#include <vector>
#include <list>

using namespace std;

int main() {
    list<int> ilst = {1,2,3,43,54,56,34,65,8};
    vector<double> dvec(ilst.begin(), ilst.end());
    vector<int> ivec = {1,2,3,4,5,6,87,9,0,0,432};
    vector<double> dvec2{ivec.begin(), ivec.end()};
}
