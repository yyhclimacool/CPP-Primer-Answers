#include <iostream>
#include <memory>
#include <string.h>
#include <string>

using namespace std;

int main() {
    const char *a = "you are the ", *b = "most beautiful girl!";
    size_t lena = strlen(a);
    size_t lenb = strlen(b);

    char *p = new char[lena + lenb + 1]();
    size_t idx = 0;
    for (const char *pa = a; *pa != '\0'; ++pa)
        p[idx++] = *pa;
    for (const char *pb = b; *pb != '\0'; ++pb)
        p[idx++] = *pb;

    cout << p << endl;

    delete [] p;
    return 0;
}
