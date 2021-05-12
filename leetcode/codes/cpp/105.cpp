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
/**
 * I. 68ms faster then 6.70%
 * II. 将getTree中两个数组的传递方式改为引用传递之后 12 ms, faster than 79.76%， 猜想与参数传递时的参数复制有关，对c++不是很了解
 */ 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l1 = preorder.size(), l2 = inorder.size();
        return getTree(preorder, 0, l1-1, inorder, 0, l2-1);
    }
private:
    TreeNode* getTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps>pe || is>ie) return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int i = is;
        for (int j = is; j <= ie; ++j)
            if (inorder[j] == preorder[ps]) {
                i = j;
                break;
            }
        root->left = getTree(preorder, ps+1, pe, inorder, is, i-1);
        root->right = getTree(preorder, ps+i-is+1, pe, inorder, i+1, ie);

        return root;
    }
};

int main()
{
    Solution a;
    int64_t t = getCurrentTime();
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    TreeNode *root = a.buildTree(pre, in);

    cout<<endl;
    cout<<getCurrentTime()-t<<endl;
    return 0;
}
