// Class Person
#include <string>

class Person {
public:
    std::string getName() const { return name; }
    std::string getAddr() const { return addr; }
    std::string name;
    std::string addr;
};
