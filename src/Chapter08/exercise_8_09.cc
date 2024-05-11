#include <iostream>
#include <sstream>

std::istream &read_print(std::istream &is) {
    std::string line;
    while(getline(is, line)) {
        std::istringstream iss(line);
        std::string sval;
        while(iss >> sval)
            std::cout << sval << std::endl;
    }
    is.clear();
    return is;
}

int main() {
;
}
