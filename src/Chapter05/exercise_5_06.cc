#include <iostream>

int main() {
    int score = 0;
    while (std::cin >> score && score >= 0 && score <= 100) {
        std::string result = (score < 60) ? "F" : 
            (score < 70) ? "D" :
            (score < 80) ? "C" :
            (score < 90) ? "B" :
            (score < 100) ? "A" : "A++";
        std::cout << result << std::endl;
    }
}
