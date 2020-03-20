#include <iostream>

using namespace std;

class Numbered {
public:
    Numbered() { sn++; mysn = sn; cout << "default ctor" << endl;}
    Numbered(const Numbered &n) {
        sn++;
        mysn = sn;
        cout << __func__ << endl;
    }
    static size_t sn;
    size_t mysn;
};

size_t Numbered::sn = 0;

void f(Numbered s) {
    cout << s.mysn << endl;
}

int main() {
    Numbered a, b = a, c = b;
    f(a); f(b); f(c);
}
