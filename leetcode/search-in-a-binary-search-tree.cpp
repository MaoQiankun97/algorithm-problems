//
// Created by riddle on 2020/10/13.
//
#include "iostream"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        while (root != nullptr) {
            if (val == root->val) {
                return root;
            }

            if (val < root->val) {
                root = root->left;
            } else if (val > root->val) {
                root = root->right;
            }
        }

        return nullptr;
    }
};

int main() {

    return 0;
}
