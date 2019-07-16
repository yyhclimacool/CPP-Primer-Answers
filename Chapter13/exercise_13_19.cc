#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    Employee(const string &n = string("")) : name(n), id(0) { ++sn; id = sn; }
    Employee(const Employee &e) : name(e.name) { ++sn; id = sn; }
    Employee &operator=(const Employee &e) {
        name = e.name;
        ++sn;
        id = sn;
        return *this;
    }
    string name;
    size_t id;
    static size_t sn;
};

size_t Employee::sn = 0;

int main() {
    Employee e;
    Employee e2;
    Employee e3 = e2;
    cout << e.id << endl;
    cout << e2.id << endl;
    cout << e3.id << endl;
}
