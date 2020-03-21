#include <iostream>
#include <memory>
#include <string>

using namespace std;

class TreeNode {
public:
    TreeNode(const std::string &s = std::string(), int ival = 0)
        : value(s), count(ival), left(nullptr), right(nullptr) {
    }
    TreeNode(const TreeNode &rhs) = default;

    TreeNode &operator=(const TreeNode &rhs) = default;

    ~TreeNode() = default;
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
    BinStrTree() : root(nullptr) {}
    BinStrTree(const BinStrTree &rhs) = default;
    BinStrTree &operator=(const BinStrTree &rhs) = default;
    ~BinStrTree() = default;
private:
    TreeNode *root;
};

int main() {
}
