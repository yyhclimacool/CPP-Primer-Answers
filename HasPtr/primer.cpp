#include "HasPtr.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    HasPtr hp("fine");
    HasPtr hp1 = hp;
    print(cout, hp1);
    return 0;
}
