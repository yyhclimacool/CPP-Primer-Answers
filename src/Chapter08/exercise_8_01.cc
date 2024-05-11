#include <iostream>

std::istream &read_print(std::istream &is) {
    int ival;
    while(is >> ival && !is.eof())
        std::cout << ival << std::endl;
    is.clear();
    return is;
}

int main() {
;
}
