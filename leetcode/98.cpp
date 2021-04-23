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
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        vector<TreeNode *> stack;
        stack.push_back(root);
        TreeNode *t = NULL;
        TreeNode *top = NULL;
        long pre = INT64_MIN;
        while (stack.size()!=0) {
            while (stack[stack.size()-1]->left!=NULL) {
                t = stack[stack.size()-1]->left;
                while (t->right!=NULL)
                    t = t->right;
                if (top!=t) {
                    stack.push_back(stack[stack.size()-1]->left);
                } else {
                    break;
                }
            }
            top = stack[stack.size()-1];
            stack.pop_back();
            if (pre>=top->val) return false;
            pre = top->val;
            if (top->right!=NULL) {
                stack.push_back(top->right);
            }
        }
        return true;
    }
};


int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    TreeNode root(3);
    TreeNode b(1);
    TreeNode c(2);
    root.left = &b;
    b.right = &c;
    cout<<a.isValidBST(&root);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
