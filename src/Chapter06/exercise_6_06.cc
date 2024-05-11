#include <iostream>

using namespace std;

int func(int ival) {
    int jval = ival;
    static int s_val = 0;
    s_val += 1;
    cout << "ival=" << ival << " jval=" << jval << " s_val=" << s_val << endl;
}

int main() {
    func(100);
    func(101);
    func(102);
    func(103);
}
