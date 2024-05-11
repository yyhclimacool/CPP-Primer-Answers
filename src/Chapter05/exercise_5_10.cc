#include <iostream>

int main() {
    char ch;
    size_t aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while (std::cin >> ch) {
        switch (ch) {
            case 'a': case 'A':
                ++aCnt;
                break;
            case 'e': case 'E':
                ++eCnt;
                break;
            case 'i': case 'I':
                ++iCnt;
                break;
            case 'o': case 'O':
                ++oCnt;
                break;
            case 'u': case 'U':
                ++uCnt;
                break;
            default:
                break;
        }
    }

    std::cout << "aCnt = " << aCnt << std::endl
              << "eCnt = " << eCnt << std::endl
              << "iCnt = " << iCnt << std::endl
              << "oCnt = " << oCnt << std::endl
              << "uCnt = " << uCnt << std::endl;
}
