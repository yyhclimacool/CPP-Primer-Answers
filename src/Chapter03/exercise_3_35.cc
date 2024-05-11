#include <iostream>
#include <iterator>

int main() {
    int ia[20];
    for (auto it = std::begin(ia); it != std::end(ia); ++it)
        *it = 0;
}
