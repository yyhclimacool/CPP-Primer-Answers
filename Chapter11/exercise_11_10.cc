#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<vector<int>::iterator, int> map1;
    // list的迭代器是双向迭代器
    map<list<int>::iterator, int> map2;

    list<int> ilst = {1,2,3,4,4,5};
    // 这里会报错，因为list的迭代器不支持<运算符
    map2.insert(make_pair(ilst.begin(), 42));
}
