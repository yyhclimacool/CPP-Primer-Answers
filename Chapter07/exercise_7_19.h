// Class Person
#include <string>

class Person {
    friend istream &read(istream &is, Person &p);
    friend ostream &print(ostream &os, const Person &p);
public:
    Person() = default;
    Person(const std::string &n, const std::string &a) : name(n), addr(a) {}
    Person(istream &is) { read(is, *this); }
    std::string getName() const { return name; }
    std::string getAddr() const { return addr; }
private:
    std::string name;
    std::string addr;
};

istream &read(istream &is, Person &p) {
    is >> p.name >> p.addr;
    return is;
}

ostream &print(ostream &os, const Person &p) {
    os << p.getName() << " " << p.getAddr();
    return os;
}
