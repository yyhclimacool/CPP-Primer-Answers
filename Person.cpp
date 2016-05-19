#include "Person.h"

using namespace std;

istream &read(istream & is, Person &p){
    is >> name >> addr;
    return is;
}

ostream &print(ostream &os, const Person &p){
    os << p.name << p.addr;
    return os;
}
