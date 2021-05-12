#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
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
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int m = root->val;
        getMaxPathSum(root, m);
        return m;
    }

private:
    int getMaxPathSum(TreeNode* root, int& m) {
        if (root==NULL) return INT32_MIN;
        int l = max(0, getMaxPathSum(root->left, m));
        int r = max(0, getMaxPathSum(root->right, m));
        int t;
        t = l+r+root->val;
        if (t>m) m = t;
        return max(l, r)+root->val;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    TreeNode *input = new TreeNode(-10);
    TreeNode *_1 = new TreeNode(9);
    TreeNode *_2 = new TreeNode(20);
    TreeNode *_3 = new TreeNode(15);
    TreeNode *_4 = new TreeNode(7);
    input->left = _1;
    input->right = _2;
    _2->left = _3;
    _2->right = _4;

    cout<<a.maxPathSum(input);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
