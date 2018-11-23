#include <iostream>

using namespace std;

int main() {
    std::cout << "/*" << std::endl;
    cout << "*/" << endl;
    cout << /* "*/" */" << endl;
    cout << /* "*/" /* "/*" */ << endl;
}
