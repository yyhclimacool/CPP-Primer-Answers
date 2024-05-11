#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<double> dvec(10, 44.33);
    // double转换成int，最终会损失精度
    cout << accumulate(dvec.cbegin(), dvec.cend(), 0) << endl;
    return 0;
}
