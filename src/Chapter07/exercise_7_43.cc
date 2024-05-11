#include <iostream>

using namespace std;

class NoDefault {
public:
    // No default constructor
    NoDefault(int i) : val(i) {}
private:
    int val;
};

class C {
public:
    C(int i = 0) : nd_(i) {}
private:
    NoDefault nd_;
};

int main() {
    std::cout << "Compilation PASS" << std::endl;
}
