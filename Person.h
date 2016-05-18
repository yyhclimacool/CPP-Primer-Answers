#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

using namespace std;

class Person{
public:
    string getName() const { return name; }
    string getAddr() const { return addr; }
private:
    string name;
    string addr;
};

#enfif // _PERSON_H_
