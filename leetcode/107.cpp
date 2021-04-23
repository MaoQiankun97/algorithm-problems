#include <iostream>
#include <algorithm>
#include <unordered_map>
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

class SolutionA {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l1 = postorder.size(), l2 = inorder.size();
        if (l1!=l2) return NULL;
        unordered_map<int, int> map;
        for (int i = 0; i < l2; i++) map[inorder[i]] = i;
        return getTree(postorder, 0, l1-1, map, 0, l2-1);
    }
private:
    TreeNode* getTree(vector<int>& postorder, int bs, int be, unordered_map<int, int>& map, int is, int ie) {
        if (bs>be || is>ie) return NULL;
        TreeNode *root = new TreeNode(postorder[be]);
        int i = map[postorder[be]];
        root->right = getTree(postorder, bs, be-1, map, i+1, ie);
        root->left = getTree(postorder, bs, be-(ie-i)-1, map, is, i-1);

        return root;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /**
         *        3
         *       / \
         *      9  20
         *        /  \
         *       15   7
         *   expected: [[15, 7], [9, 20], [3]];
         */
        if (root==NULL) return {};
        vector<vector<int>> r_stack;
        vector<TreeNode *> queue;
        vector<vector<int>> result;

        queue.push_back(root);
        while (queue.size()!=0) {
            vector<int> temp;
            vector<TreeNode *> Tree_temp;
            for (int i = 0; i < queue.size(); i++) {
                temp.push_back(queue[i]->val);
                if (queue[i]->left!=NULL) {
                    Tree_temp.push_back(queue[i]->left);
                }
                if (queue[i]->right!=NULL) {
                    Tree_temp.push_back(queue[i]->right);
                }
            }
            r_stack.push_back(temp);
            queue = Tree_temp;
        }
        while (r_stack.size()!=0) {
            result.push_back(r_stack[r_stack.size()-1]);
            r_stack.pop_back();
        }
        return result;
    }
};

int main()
{
    SolutionA a;
    int64_t t = getCurrentTime();
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    TreeNode *root = a.buildTree(pre, in);
    Solution b;
    b.levelOrderBottom(root);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
