#include <vector>
#include <iostream>

using namespace std;

vector<int> *get_vec() {
    return new vector<int>;
}

vector<int> *func(vector<int> *vp) {
    int ival;
    while (cin >> ival)
        vp->push_back(ival);
    return vp;
}

void use_vec(vector<int> *vp) {
    for (const auto &e : *vp)
        cout << e << '\t';
    cout << endl;
}

int main() {
    auto p = get_vec();
    use_vec(func(p));
    delete p;
}
