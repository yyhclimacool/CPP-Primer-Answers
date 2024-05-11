#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

vector<int> *get_vec() {
    return new vector<int>(4, 42);
}

vector<int> *func(vector<int> *vp) {
    int ival;
    while (cin >> ival)
        vp->push_back(ival);
    return vp;
}

void use_vec(vector<int> *vp) {
    std::copy(vp->cbegin(), vp->cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    auto p = get_vec();
    use_vec(func(p));
    delete p;
}
