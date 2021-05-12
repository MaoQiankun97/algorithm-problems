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
    vector<TreeNode *> getResult(int start, int end) {
        if (start>end) return {NULL};
        vector<TreeNode*> all_trees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left_trees = getResult(start, i-1);
            vector<TreeNode*> right_trees = getResult(i+1, end);

            for (int j = 0; j < left_trees.size(); ++j) {
                for (int k = 0; k < right_trees.size(); ++k) {
                    TreeNode *root;
                    root = (TreeNode *)malloc(sizeof(TreeNode));
                    root->val = i;
                    root->left = left_trees[j];
                    root->right = right_trees[k];
                    all_trees.push_back(root);
                }
            }
        }
        return all_trees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<TreeNode*> r = getResult(1, n);
        return r;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<TreeNode *> r = a.generateTrees(3);
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
