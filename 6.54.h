#include <vector>

int func(int, int);
using fp = int (*)(int, int);

std::vector<int (*)(int, int)> f_vec1;

std::vector<fp> f_vec2;
