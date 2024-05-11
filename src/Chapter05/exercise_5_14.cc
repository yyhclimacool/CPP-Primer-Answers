#include <iostream>
#include <string>

int main() {
    std::string sval, curr_str, res_str;
    size_t curr_cnt = 0, res_cnt = 0;

    if (std::cin >> sval) {
        curr_str = sval;
        curr_cnt = 1;
        while (std::cin >> sval) {
            if (sval == curr_str) {
                ++curr_cnt;
                if (curr_cnt > res_cnt) {
                    res_cnt = curr_cnt;
                    res_str = curr_str;
                }
            }
            else {
                if (curr_cnt > res_cnt) {
                    res_cnt = curr_cnt;
                    res_str = curr_str;
                }
                curr_cnt = 1;
                curr_str = sval;
            }
        }
    }

    if (res_cnt > 1)
        std::cout << res_str << " occurs " << res_cnt << " times" << std::endl;
    else
        std::cout << "There is no duplicated word" << std::endl;
}
