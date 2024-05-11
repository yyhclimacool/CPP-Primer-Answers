#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    std::cout << "success" << std::endl;
    std::cout << make_plural(2, "success", "es") << std::endl;

    std::cout << "failure" << std::endl;
    std::cout << make_plural(2, "failure") << std::endl;
}
