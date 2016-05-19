#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

using namespace std;

class Person{
    friend istream &read(istream &, Person &);
    friend ostream &print(ostream &, const Person &);
public:
    Person() = default;
    Person(const string &n, const string &a):name(n), addr(a){}
    
    ~Person(){}
    
    string getName() const { return name; }
    string getAddr() const { return addr; }
private:
    string name;
    string addr;
};

istream &read(istream & is, Person &p);
ostream &print(ostream &os, const Person &p);

#enfif // _PERSON_H_
