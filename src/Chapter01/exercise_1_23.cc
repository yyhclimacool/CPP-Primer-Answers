#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item currItem, val;
    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val.isbn() == currItem.isbn())
                ++cnt;
            else {
                std::cout << "The book " << currItem.isbn() << " sold " << cnt << std::endl;
                currItem = val;
                cnt = 1;
            }
        }
        std::cout << "The book " << currItem.isbn() << " sold " << cnt << std::endl;
    }
    return 0;
}
