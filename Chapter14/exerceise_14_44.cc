#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

int add(int i, int j) {
    return i + j;
}

auto mod = [] (int a, int b) { return a % b; };

struct divide {
    int operator()(int i, int j) {
        return i / j;
    }
};

int main() {
    map<string, function<int (int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"*", [] (int a, int b) { return a * b; }},
        {"/", divide()},
        {"%", mod}
    };

    cout << binops["-"](20, 17) << endl;
}
