#include <vector>
#include <iostream>
#include <memory>

using namespace std;

using spvec = shared_ptr<vector<int>>;
spvec get_vec() {
    return make_shared<vector<int>>();
}

spvec func(spvec vp) {
    int ival;
    while (cin >> ival)
        vp->push_back(ival);
    return vp;
}

void use_vec(spvec vp) {
    for (const auto &e : *vp)
        cout << e << '\t';
    cout << endl;
}

int main() {
    auto p = get_vec();
    use_vec(func(p));
}
