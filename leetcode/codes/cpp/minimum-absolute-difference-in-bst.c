#include <stdio.h>
#include <malloc.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void midOrder(struct TreeNode* root, int* pre, int* result) {
    if (root == NULL) {
        return;
    }
    midOrder(root->left, pre, result);
    if (* pre == -1) {
        * pre = root->val;
    } else {
        *result = *result > root->val - *pre ? root->val - *pre : *result;
        * pre = root->val;
    }
    midOrder(root->right, pre, result);
}

int getMinimumDifference(struct TreeNode *root) {
    int result = 1 << 30;
    int pre = -1;
    midOrder(root, &pre, &result);

    return result;
}

int main() {
    struct TreeNode* root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = NULL;
    struct TreeNode* a = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    a->val = 3;
    a->right = NULL;
    struct TreeNode* b = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    b->val = 2;
    b->left = NULL;
    b->right = NULL;
    root->right = a;
    a->left = b;
    printf("%d", getMinimumDifference(root));

    return 0;
}