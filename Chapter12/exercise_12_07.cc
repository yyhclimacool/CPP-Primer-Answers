#include <vector>
#include <iostream>
#include <memory>
#include <iterator>

using namespace std;

using spvec = shared_ptr<vector<int>>;

spvec get_vec() {
    return make_shared<vector<int>>(4, 42);
}

spvec func(spvec vp) {
    istream_iterator<int> input(cin), eof;
    std::copy(input, eof, back_inserter(*vp));
    return vp;
}

void use_vec(spvec vp) {
    std::copy(vp->cbegin(), vp->cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    auto p = get_vec();
    use_vec(func(p));
}
