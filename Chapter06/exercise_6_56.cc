#include "exercise_6_55.h"
#include <iostream>

int main() {
    for (auto &e : funcs)
        std::cout << e(42, 42) << std::endl;
}
