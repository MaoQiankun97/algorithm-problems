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
    void getHeight(TreeNode * p, int &h, int cur_h) {
        if (p->left==NULL && p->right==NULL) return;
        cur_h++;
        if (cur_h>h) h = cur_h;
        if (p->left!=NULL)
            getHeight(p->left, h, cur_h);
        if (p->right!=NULL)
            getHeight(p->right, h, cur_h);
    }

public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int h = 1;
        getHeight(root, h, 1);
        return h;
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
    cout<<a.maxDepth(&root);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
