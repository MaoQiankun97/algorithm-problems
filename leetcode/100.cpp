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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL || q==NULL) return p==q;
        return p->val==q->val&&isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
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
    root.right = &c;
    TreeNode root1(1);
    TreeNode b1(2);
    TreeNode c1(3);
    root1.left = &b1;
    root1.right = &c1;
    cout<<a.isSameTree(&root, &root1);
    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
