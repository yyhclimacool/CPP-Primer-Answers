#include <iostream>

using namespace std;

template<typename T, size_t N>
T *mybegin(T (&arr) [N]) {
    return &arr[0];
}

template <typename T, size_t N>
T *myend(T (&arr) [N]) {
    return &arr[N];
}

int main() {
    int arri[] = {};
    int arri1[] = {1,2,3,4};

    for (auto *i = mybegin(arri1); i != myend(arri1); ++i)
        cout << *i << ", ";
    cout << endl;
}
