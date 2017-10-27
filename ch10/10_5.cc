#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<string> roster1 = {"abby", "kevin", "john", "slaughter"};
    vector<string> roster2 = {"abby", "kevin", "john", "slaughter"};

    cout << "equal or not : " << equal(roster2.cbegin(), roster2.cend(), roster1.cbegin());
}
