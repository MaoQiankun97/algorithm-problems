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
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;        
        int hl = getHeight(root->left);
        int hr = getHeight(root->right);
        if (max(hl, hr)-min(hl, hr)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
private:
    int getHeight(TreeNode *root) {
        if (root == NULL) return 0;
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    cout<<a.isBalanced(new TreeNode(1));
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
