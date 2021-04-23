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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL) return 1;
        if (root->left==NULL) return 1+minDepth(root->right);
        if (root->right==NULL) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.minDepth(new TreeNode(1));
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
