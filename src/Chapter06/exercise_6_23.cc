#include <iostream>

using namespace std;

void print1(const int *a, size_t sz) {
    for (size_t idx = 0; idx != sz; ++idx) {
        cout << *(a + idx) << " ";
    }
    cout << endl;
}
void print2(const int a[], size_t sz) {
    for (size_t idx = 0; idx != sz; ++idx) {
        cout << a[idx] << " ";
    }
    cout << endl;
}
void print3(const int a[10], size_t sz) {
    for (size_t idx = 0; idx != sz; ++idx) {
        cout << a[idx] << " ";
    }
    cout << endl;
}

void print4(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

void print5(int (&a)[2]) {
    for (auto elem : a) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    int i = 0, j[2] = {0, 1};
    print1(&i, 1);
    print1(j, 2);

    print2(&i, 1);
    print2(j, 2);

    print3(&i, 1);
    print3(j, 2);

    print4(&i, &i + 1);
    print4(begin(j), end(j));

    print5(j);
}
