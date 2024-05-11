#include <iostream>

int main(int argc, char *argv[]) {
    char **start = &argv[0];
    while (*start != 0) {
        std::cout << *start++ << std::endl;
    }
}
