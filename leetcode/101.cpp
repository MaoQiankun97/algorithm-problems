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

class Solution {
private:
    bool getResult(TreeNode *left, TreeNode *right) {
        if (left==NULL && right==NULL) return true;      
        if (left==NULL || right==NULL) return false;
        if (left->val != right->val) return false;
        return getResult(left->left, right->right)&&getResult(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return getResult(root->left, root->right);
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    TreeNode root(1);   
    TreeNode b(2);
    TreeNode c(2);
    root.left = &b;
    root.right = &c;
    cout<<a.isSymmetric(&root);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
