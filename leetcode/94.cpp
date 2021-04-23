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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        vector<int> result;
        vector<TreeNode*> stack;
        stack.push_back(root);
        TreeNode *top = NULL;
        TreeNode *left_right = NULL;
        while (stack.size()!=0) {
            while (stack[stack.size()-1]->left!=NULL) {
                left_right = stack[stack.size()-1]->left;
                while (left_right->right!=NULL) left_right = left_right->right;
                if (top!=left_right)
                    stack.push_back(stack[stack.size() - 1]->left);
                else break;
            }
            top = stack[stack.size()-1];
            result.push_back(top->val);
            stack.pop_back();
            if (top->right!=NULL) {
                stack.push_back(top->right);
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    TreeNode root(1);
    TreeNode b(2);
    TreeNode c(3);
    root.left = &b;
    b.right = &c;
    vector<int> r = a.inorderTraversal(&root);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
