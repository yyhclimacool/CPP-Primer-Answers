#include <iostream>

using namespace std;

int main() {
    int *ip = new int[10]();
    delete [] ip;
}
