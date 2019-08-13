#include <iostream>

using namespace std;

template <typename T, unsigned N>
void print(T (&arr) [N]) {
    for (auto &elem : arr)
        cout << elem << ",";
    cout << endl;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    string arr_str[] = {"fine", "by", "me"};

    print(arr);
    print(arr_str);
}
