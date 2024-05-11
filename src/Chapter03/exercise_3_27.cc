#include <iostream>

using namespace std;

constexpr int text_size() {
    return 42;
}

int main() {
    constexpr unsigned buf_size = 1024;
    int ia[buf_size];
    int ia2[4*7 - 14];
    int ia3[text_size()];
    char st[12] = "fundamental";
}
