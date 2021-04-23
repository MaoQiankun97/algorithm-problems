#include <iostream>
#include <algorithm>
#include <vector>
#include <sys/time.h>      //添加头文件
using namespace std;

int64_t getCurrentTime()      //直接调用这个函数就行了，返回值最好是int64_t，long long应该也可以
{
    struct timeval tv;
    gettimeofday(&tv,NULL);    //该函数在sys/time.h头文件中
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool compare(TreeNode *a, TreeNode *b) {
    return a->val<b->val;
}
/**
 * 这个算法在leetcode上submit不能ac
 * 但是wrong answer对应的test case在console中run code却可以得到正确的结果
 */
class Solution {
private:
    static void setVector(TreeNode* root, vector<int> &intArr) {
        if (root == nullptr) {
            return;
        }

        setVector(root->left, intArr);
        intArr.push_back(root->val);
        setVector(root->right, intArr);
    }

    static void setVal(TreeNode* root, int& i, const vector<int> intArr) {
        if (root == nullptr) {
            return;
        }
        setVal(root->left, i, intArr);
        root->val = intArr[i++];
        setVal(root->right, i, intArr);
    }

public:
    static void recoverTree(TreeNode* root) {
        vector<int> intArr;
        int i = 0;
        setVector(root, intArr);
        sort(intArr.begin(), intArr.end());
        setVal(root, i, intArr);
    }
};

/**
 * 中序遍历.
 */
void midOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    midOrder(root->left);
    cout<<root->val<<" ";
    midOrder(root->right);
}

int main()
{
    int64_t t = getCurrentTime();
    TreeNode root(1);
    TreeNode b(2);
    TreeNode c(3);
    root.left = &b;
    root.right = &c;
    midOrder(&root);
    cout<<endl;
    Solution::recoverTree(&root);
    midOrder(&root);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}