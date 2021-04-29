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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root==NULL) return {};
        vector<vector<int>> result;
        vector<TreeNode *> stack;
        result.push_back({root->val});
        stack.push_back(root);
        bool h = true;;
        while(stack.size()!=0) {
            vector<int> r_temp;
            vector<TreeNode *> temp;
            for (int i = stack.size()-1; i >= 0; --i) {
                if (h) {
                    if (stack[i]->right != NULL) {
                        r_temp.push_back(stack[i]->right->val);
                        temp.push_back(stack[i]->right);
                    }
                    if (stack[i]->left != NULL) {
                        r_temp.push_back(stack[i]->left->val);
                        temp.push_back(stack[i]->left);
                    }
                } else {
                    if (stack[i]->left != NULL) {
                        r_temp.push_back(stack[i]->left->val);
                        temp.push_back(stack[i]->left);
                    }
                    if (stack[i]->right != NULL) {
                        r_temp.push_back(stack[i]->right->val);
                        temp.push_back(stack[i]->right);
                    }
                }
            }
            if (r_temp.size()!=NULL)
                result.push_back(r_temp);
            stack = temp;
            h = !h;
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
    TreeNode c(2);
    root.left = &b;
    b.right = &c;
    vector<vector<int>> r = a.zigzagLevelOrder(&root);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
