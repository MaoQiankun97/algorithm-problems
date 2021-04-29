#include "iostream"
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode *root) {
        return countNodesP(root);
    }

private:
    int countNodesP(TreeNode* p) {
        if (p == nullptr) {
            return 0;
        }

        return countNodes(p->left) + countNodes(p->right) + 1;
    }
};

int main() {
    Solution a;

    return 0;
}
