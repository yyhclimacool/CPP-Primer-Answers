#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Only accept 2 params" << std::endl;
        return 0;
    }
    std::string res = std::string(argv[1]) + std::string(argv[2]);
    std::cout << res << std::endl;
}
