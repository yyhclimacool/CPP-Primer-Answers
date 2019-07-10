#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<vector<int>::iterator, int> map1;
    // list的迭代器是双向迭代器
    map<list<int>::iterator, int> map2;
}
