#include <iostream>
#include <string>

int main() {
    std::string sval, prestr;
    bool dup = false;

    while (std::cin >> sval && sval.size()) {
        if (islower(sval[0]))
            continue;
        if (sval == prestr) {
            std::cout << "Duplicate word!" << std::endl;
            dup = true;
            break;
        } else 
            prestr = sval;
    }

    if (!dup)
        std::cout << "No duplicate word" << std::endl;
}
