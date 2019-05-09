#include <iostream>

int main() {
    char ch;
    size_t aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    size_t spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    char prech = '\0';
    size_t ffCnt = 0, flCnt = 0, fiCnt = 0;
    while (std::cin >> std::noskipws >> ch) {
        switch (ch) {
            case 'a': case 'A':
                ++aCnt;
                break;
            case 'e': case 'E':
                ++eCnt;
                break;
            case 'i': case 'I':
                ++iCnt;
                if (prech == 'f') ++fiCnt;
                break;
            case 'o': case 'O':
                ++oCnt;
                break;
            case 'u': case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spaceCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlineCnt;
                break;
            case 'l':
                if (prech == 'f') ++flCnt;
                break;
            case 'f':
                if (prech == 'f') ++ffCnt;
                break;
            default:
                break;
        }
        prech = ch;
    }

    std::cout << "aCnt = " << aCnt << std::endl
              << "eCnt = " << eCnt << std::endl
              << "iCnt = " << iCnt << std::endl
              << "oCnt = " << oCnt << std::endl
              << "uCnt = " << uCnt << std::endl

              << "spaceCnt   = " << spaceCnt << std::endl
              << "tabCnt     = " << tabCnt << std::endl
              << "newlineCnt = " << newlineCnt << std::endl

              << "ffCnt = " << ffCnt << std::endl
              << "flCnt = " << flCnt << std::endl
              << "fiCnt = " << fiCnt << std::endl;
}
