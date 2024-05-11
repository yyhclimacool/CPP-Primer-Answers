#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold{0};
    double revenue{0};
};

int main() {
    Sales_data sd;
    std::cout << "sizeof(Sales_data) = " << sizeof(sd) << std::endl;
    return 0;
}
