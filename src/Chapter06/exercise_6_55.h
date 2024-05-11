#ifndef _6_55_H
#define _6_55_H

#include <vector>
using FuncP = int (*)(int, int);

int add(int lhs, int rhs) {
    return lhs + rhs;
}

int minus(int lhs, int rhs) {
    return lhs - rhs;
}

int multi(int lhs, int rhs) {
    return lhs * rhs;
}

int divide(int lhs, int rhs) {
    return (rhs != 0) ? lhs / rhs : 0;
}

std::vector<FuncP> funcs{add, minus, multi, divide};

#endif
