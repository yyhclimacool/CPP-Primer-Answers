#include <iostream>

int main() {
    int score = 0;
    while (std::cin >> score && score >= 0 && score <= 100) {
        if (score < 60)
            std::cout << 'F' << std::endl;
        else if (score < 70)
            std::cout << 'D' << std::endl;
        else if (score < 80)
            std::cout << 'C' << std::endl;
        else if (score < 90)
            std::cout << 'B' << std::endl;
        else if (score < 100)
            std::cout << 'A' << std::endl;
        else if (score == 100)
            std::cout << "A++" << std::endl;
    }
}
