#include <iostream>

size_t calling_cnt() {
    static size_t cnt = 0;
    return ++cnt;
}

int main() {
    for (size_t i = 0; i < 20; ++i)
        std::cout << "Funtion calling " << calling_cnt() << " times!" << std::endl;
}
