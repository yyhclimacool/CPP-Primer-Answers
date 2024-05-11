#include <iostream>
#include <string>

std::string global_str; // default constructed empty string
int global_int; // default 0
int main() {
    int local_int; // default not known
    std::string local_str; // default constructed empty string

    std::cout << "global_str: " << global_str << std::endl;
    std::cout << "global_int: " << global_int << std::endl;
    std::cout << "local_int : " << local_int << std::endl;
    std::cout << "local_str : " << local_str << std::endl;
}
