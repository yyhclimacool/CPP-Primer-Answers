#include <iostream>
#include <vector>

using namespace std;

class NoDefault {
public:
  NoDefault(int a) { cout << a << endl; }
};

// 实例化默认构造函数的时候会new NoDefault，这时需要默认构造函数
// template class vector<NoDefault>;

int main() {
  NoDefault nd(4);
}
