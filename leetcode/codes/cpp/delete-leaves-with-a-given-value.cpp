#include "iostream"
#include "vector"
#include "unordered_map"
#include "map"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        afterOrder(root, nullptr, false, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }

        return root;
    }

private:
    void afterOrder(TreeNode *root, TreeNode *pre, bool isleft, int target) {
        if (root == nullptr) {
            return;
        }
        afterOrder(root->left, root, true, target);
        afterOrder(root->right, root, false, target);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            if (pre != nullptr) {
                if (isleft) {
                    pre->left = nullptr;
                } else {
                    pre->right = nullptr;
                }
            }
        }
    }
};

int main() {
    auto root = new TreeNode(5);
    auto left = new TreeNode(2);
    auto righ = new TreeNode(-3);
    root->left = left;
    root->right = righ;
    Solution a;
    a.removeLeafNodes(left, 2);

    return 0;
}
